#ifndef DISSIMILARITYMATRIX_H
#define DISSIMILARITYMATRIX_H

#include <memory>
#include <vector>
#include <tuple>
#include <map>
#include "datanode.h"

class DissimilarityMatrix
{
    private:
    std::map< std::tuple<int, int>, float > _diffVals;
    int _numItems;

    public:
    void setNumItems(int count);
    void setDiffVal(int id_0, int id_1, double val);
    double getDiffVal(int id_0, int id_1);
    std::vector< std::shared_ptr<DataNode> > getEigenDecomp(int order);
};

#endif
