#ifndef EUCLIDEANDISTANCEPROCESSOR_H
#define EUCLIDEANDISTANCEPROCESSOR_H

#include "idistanceprocessor.h"

class EuclideanDistanceProcessor: public IDistanceProcessor
{
    private:
    std::vector< std::shared_ptr<DataNode> > _dataNodes;

    public:
    virtual void setDataNodes(std::vector< std::shared_ptr<DataNode> > dataSet);
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix();
};

#endif
