#ifndef PROJPIPELINE_H
#define PROJPIPELINE_H

#include <vector>
#include <memory>
#include <datanode.h>
#include <distanceprocessor.h>
#include <dissimilaritymatrix.h>

class ProjPipeline
{
    private:
    std::vector< std::shared_ptr<DataNode> > _dataNodes;
    std::shared_ptr<DistanceProcessor> _distanceProcessor;
    int _maxOrder;

    public:
    ProjPipeline();
    void update();
    void addDataNode(std::shared_ptr<DataNode> dataNode);
    void setDistanceProcessor(std::shared_ptr<DistanceProcessor> distanceProcessor);
    std::vector< std::shared_ptr<DataNode> > getEigenDecomp(int order);
};

#endif
