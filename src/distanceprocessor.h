#ifndef DISTANCEPROCESSOR_H
#define DISTANCEPROCESSOR_H

#include <vector>
#include <memory>
#include <dissimilaritymatrix.h>

class DistanceProcessor
{
    protected:
    std::vector< std::shared_ptr<DataNode> > _dataNodes;

    public:
    virtual void setDataNodes(std::vector< std::shared_ptr<DataNode> > dataSet);
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix();

    protected:
    virtual double _getDistance(int id0, int id1);
};

#endif
