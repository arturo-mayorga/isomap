#ifndef MANIFOLDDISTANCEPROCESSOR_H
#define MANIFOLDDISTANCEPROCESSOR_H

#include <distanceprocessor.h>
#include <manifoldnode.h>

class ManifoldDistanceProcessor: public DistanceProcessor
{
    public:
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix();
    std::vector<ManifoldNode*> getManifoldTopology();
};

#endif