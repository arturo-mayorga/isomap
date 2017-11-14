#include <iostream>
#include <limits>
#include <vector>
#include <queue>

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

    // populate topology
    for (int i = 0; i < nodeCount; ++i)
    {
        ManifoldNode *node = masterList[i];

        for (int j = 0; j < nodeCount; ++j)
        {
            if (i != j && dMat->getDiffVal(i, j) <= minD)
            {
                node->children.push_back(masterList[j]);
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