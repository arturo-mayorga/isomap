#include <iostream>
#include <projpipeline.h>

ProjPipeline::ProjPipeline()
{
    this->_maxOrder = 0;
}

void ProjPipeline::update()
{
    this->_distanceProcessor->setDataNodes(this->_dataNodes);
}

void ProjPipeline::addDataNode(std::shared_ptr<DataNode> dataNode)
{
    this->_dataNodes.push_back(dataNode);
}

void ProjPipeline::setDistanceProcessor(std::shared_ptr<DistanceProcessor> distanceProcessor)
{
    this->_distanceProcessor = distanceProcessor;
}

std::vector< std::shared_ptr<DataNode> > ProjPipeline::getEigenDecomp(int order)
{
    auto diffMatrix = this->_distanceProcessor->getDissimilarityMatrix();
    auto retData = diffMatrix->getEigenDecomp(order);

    for(auto i = 0; i < retData.size(); ++i) {
        retData[i]->id = this->_dataNodes[i]->id;
    }

    return retData;
}

