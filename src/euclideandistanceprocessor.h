#ifndef EUCLIDEANDISTANCEPROCESSOR_H
#define EUCLIDEANDISTANCEPROCESSOR_H

#include <distanceprocessor.h>

class EuclideanDistanceProcessor: public DistanceProcessor
{
    protected:
    virtual double _getDistance(int id0, int id1);
};

#endif
