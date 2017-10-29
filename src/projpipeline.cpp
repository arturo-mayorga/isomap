#include <iostream>
#include "projpipeline.h"

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

void ProjPipeline::setDistanceProcessor(std::shared_ptr<IDistanceProcessor> distanceProcessor)
{
    this->_distanceProcessor = distanceProcessor;
}

std::vector< std::shared_ptr<DataNode> > ProjPipeline::getEigenDecomp(int order)
{
    auto diffMatrix = this->_distanceProcessor->getDissimilarityMatrix();
    return diffMatrix->getEigenDecomp(order);
}

