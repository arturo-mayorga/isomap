#include <algorithm>
#include "dissimilaritymatrix.h"

void DissimilarityMatrix::setNumItems(int count)
{
    this->_numItems = count;
}

void DissimilarityMatrix::setDiffVal(int id_0, int id_1, double val)
{
    int a = std::min(id_0, id_1);
    int b = std::max(id_0, id_1);

    this->_diffVals[std::tuple<int, int>(a, b)] = val;
}

double DissimilarityMatrix::getDiffVal(int id_0, int id_1)
{
    int a = std::min(id_0, id_1);
    int b = std::max(id_0, id_1);

    return this->_diffVals[std::tuple<int, int>(a, b)];
}

std::vector< std::shared_ptr<DataNode> > DissimilarityMatrix::getEigenDecomp(int order)
{
    std::vector< std::shared_ptr<DataNode> > ret;

    std::vector<std::vector<double>> matrix;
    matrix.resize(this->_numItems, std::vector<double>(this->_numItems, 0));

    for (int i = 0; i < this->_numItems; ++i)
    {
        for (int j = 0; j < this->_numItems; ++j)
        {
            matrix[i][j] = this->getDiffVal(i, j);
        }
    }

    // todo: this is not real
    for (int i = 0; i < this->_numItems; ++i)
    {
        auto t = std::make_shared<DataNode>();
        t->id = i;
        for (int o = 0; o < order; ++o)
        {
            double v = (o < this->_numItems) ? matrix[i][o] : 0.0;
            t->dataSet.push_back(v);
        }
        ret.push_back(t);
    }

    return ret;
}

