#ifndef PROJPIPELINE_H
#define PROJPIPELINE_H

#include <vector>
#include <memory>
#include "datanode.h"
#include "idistanceprocessor.h"
#include "dissimilaritymatrix.h"

class ProjPipeline
{
    public:
    void addDataNode(std::shared_ptr<DataNode> dataNodes);
    void setDistanceProcessor(std::shared_ptr<IDistanceProcessor> distanceProcessor);
};

#endif
