#include <memory>
#include <iostream>
#include <math.h>
#include <euclideandistanceprocessor.h>

double EuclideanDistanceProcessor::_getDistance(int id0, int id1)
{
    auto nodeA = this->_dataNodes[id0];
    auto nodeB = this->_dataNodes[id1];

    double distSq = 0;
    int order = std::max(nodeA->dataSet.size(), nodeB->dataSet.size());

    for (int d = 0; d < order; ++d)
    {
        double vA = (d < nodeA->dataSet.size()) ? nodeA->dataSet[d] : 0.0;
        double vB = (d < nodeB->dataSet.size()) ? nodeB->dataSet[d] : 0.0;

        distSq += (vA - vB) * (vA - vB);
    }

    return sqrt(distSq);
}