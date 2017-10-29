#include <memory>
#include <iostream>
#include <math.h>
#include "euclideandistanceprocessor.h"

void EuclideanDistanceProcessor::setDataNodes(std::vector< std::shared_ptr<DataNode> > dataSet)
{
    this->_dataNodes = dataSet;
}

std::shared_ptr<DissimilarityMatrix> EuclideanDistanceProcessor::getDissimilarityMatrix()
{
    auto retMat = std::make_shared<DissimilarityMatrix>();

    retMat->setNumItems(this->_dataNodes.size());

    for (int i = 0; i < this->_dataNodes.size(); ++i)
    {
        for (int j = i + 1; j < this->_dataNodes.size(); ++j)
        {
            auto nodeA = this->_dataNodes[i];
            auto nodeB = this->_dataNodes[j];

            double distSq = 0;
            int order = std::max(nodeA->dataSet.size(), nodeB->dataSet.size());

            for (int d = 0; d < order; ++d)
            {
                double vA = (d < nodeA->dataSet.size()) ? nodeA->dataSet[d] : 0.0;
                double vB = (d < nodeB->dataSet.size()) ? nodeB->dataSet[d] : 0.0;

                distSq += (vA - vB) * (vA - vB);
            }

            double dist = sqrt(distSq);
            retMat->setDiffVal(i, j, dist);
        }
    }

    return retMat;
}