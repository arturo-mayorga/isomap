#ifndef IDISTANCEPROCESSOR_H
#define IDISTANCEPROCESSOR_H

#include <vector>
#include <memory>
#include "dissimilaritymatrix.h"

class IDistanceProcessor
{
    public:
    virtual void setDataSet(std::vector< std::shared_ptr<DataNode> > dataSet) = 0;
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix() = 0;
};

#endif
