#include <distanceprocessor.h>

void DistanceProcessor::setDataNodes(std::vector< std::shared_ptr<DataNode> > dataSet)
{
    this->_dataNodes = dataSet;
}

std::shared_ptr<DissimilarityMatrix> DistanceProcessor::getDissimilarityMatrix()
{
    auto retMat = std::make_shared<DissimilarityMatrix>();

    retMat->setNumItems(this->_dataNodes.size());

    for (int i = 0; i < this->_dataNodes.size(); ++i)
    {
        for (int j = i + 1; j < this->_dataNodes.size(); ++j)
        {
            double dist = this->_getDistance(i, j);
            retMat->setDiffVal(i, j, dist);
        }
    }

    return retMat;
}
