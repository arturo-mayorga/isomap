#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <algorithm>

#include <manifolddistanceprocessor.h>
#include <euclideandistanceprocessor.h>
#include <manifoldnode.h>

using namespace std;

void dijkstra(ManifoldNode *root)
{
    queue<ManifoldNode*> q;
    root->distance = 0;
    q.push(root);

    while (!q.empty())
    {
        auto n = q.front();
        q.pop();

        for (auto c : n->children)
        {
            if (c->distance == -1)
            {
                c->distance = n->distance + 1;
                q.push(c);
            }
        }
    }
}

std::shared_ptr<DissimilarityMatrix> ManifoldDistanceProcessor::getDissimilarityMatrix()
{
    EuclideanDistanceProcessor dp;
    dp.setDataNodes(this->_dataNodes);
    auto dMat = dp.getDissimilarityMatrix();

    double minD = 0;

    int nodeCount = this->_dataNodes.size();

    for (int i = 0; i < nodeCount; ++i)
    {
        double closestD = numeric_limits<double>::max();

        for (int j = 0; j < nodeCount; ++j)
        {
            if (i != j)
            {
                double diff = dMat->getDiffVal(i, j);
                if (closestD > diff)
                {
                    closestD = diff;
                }
            }
        }
        if (minD < closestD)
        {
            minD = closestD;
        }
    }

    vector<ManifoldNode*> masterList;

    for (int i = 0; i < nodeCount; ++i)
    {
        masterList.push_back(new ManifoldNode());
    }

    int maxChildren = 3;

    // populate topology
    for (int i = 0; i < nodeCount; ++i)
    {
        ManifoldNode *node = masterList[i];

        vector<double> distances;

        make_heap(distances.begin(), distances.end(), std::greater<double>());

        for (int j = 0; j < nodeCount; ++j)
        {
            auto diffVal = dMat->getDiffVal(i, j);
            if (i != j && diffVal <= minD)
            {
                distances.push_back(diffVal);
                std::push_heap (distances.begin(),distances.end(), std::greater<double>());
            }
        }

        for (int j = 0; j < maxChildren; ++j)
        {
            std::pop_heap (distances.begin(),distances.end(), std::greater<double>());
            distances.pop_back();
        }

        double maxD = distances.front();

        for (int j = 0; j < nodeCount; ++j)
        {
            auto diffVal = dMat->getDiffVal(i, j);
            if (i != j && diffVal <= maxD)
            {
                node->children.push_back(masterList[j]);
            }
        }
    }

    // make sure the connections go both ways
    for (auto node : masterList)
    {
        for (auto child : node->children)
        {
            int found = 0;
            for (auto gChild : child->children)
            {
                if (gChild == node)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                child->children.push_back(node);
            }
        }
    }

    auto retMat = std::make_shared<DissimilarityMatrix>();

    retMat->setNumItems(this->_dataNodes.size());

    for (int i = 0; i < nodeCount; ++i)
    {
        // reset distance
        for (int j = 0; j < nodeCount; ++j)
        {
            masterList[j]->distance = -1;
        }

        dijkstra(masterList[i]);

        for (int j = 0; j < nodeCount; ++j)
        {
            auto n = masterList[j];
            retMat->setDiffVal(i, j, n->distance);
        }
    }

    for (int i = 0; i < nodeCount; ++i)
    {
        ManifoldNode* mn = masterList[i];
        delete mn;
    }

    return retMat;
}