#ifndef MANIFOLDDISTANCEPROCESSOR_H
#define MANIFOLDDISTANCEPROCESSOR_H

#include <distanceprocessor.h>

class ManifoldDistanceProcessor: public DistanceProcessor
{
    public:
    virtual std::shared_ptr<DissimilarityMatrix> getDissimilarityMatrix();

    protected:
    virtual double _getDistance(int id0, int id1);
    void _prepareGraph();
};

#endif