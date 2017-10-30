#include <manifolddistanceprocessor.h>
#include <euclideandistanceprocessor.h>

std::shared_ptr<DissimilarityMatrix> ManifoldDistanceProcessor::getDissimilarityMatrix()
{
    this->_prepareGraph();
    return DistanceProcessor::getDissimilarityMatrix();
}

double ManifoldDistanceProcessor::_getDistance(int id0, int id1)
{
    return 0.0;
}

void ManifoldDistanceProcessor::_prepareGraph()
{
    EuclideanDistanceProcessor dp;
    dp.setDataNodes(this->_dataNodes);
    auto dMat = dp.getDissimilarityMatrix();
}