#ifndef MANIFOLDDISTANCEPROCESSOR_H
#define MANIFOLDDISTANCEPROCESSOR_H

#include <distanceprocessor.h>

class ManifoldDistanceProcessor: public DistanceProcessor
{
    public:
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix();
};

#endif