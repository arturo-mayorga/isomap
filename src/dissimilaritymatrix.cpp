#include <algorithm>
#include "dissimilaritymatrix.h"

#include <iostream>
#include <Eigen/Eigenvalues>
#include "Eigen/Core"

using namespace Eigen;
using namespace std;

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

    MatrixXd A(this->_numItems, this->_numItems);

    for (int i = 0; i < this->_numItems; ++i)
    {
        for (int j = 0; j < this->_numItems; ++j)
        {
            A(i, j) = this->getDiffVal(i, j);
        }
    }

    // cout << "The dissimilarity matrix is:" << endl << A << endl << endl;

    // http://eigen.tuxfamily.org/dox/classEigen_1_1SelfAdjointEigenSolver.html
    SelfAdjointEigenSolver<MatrixXd> es(A);
    MatrixXd V = es.eigenvectors();
    // cout << "The matrix of eigenvectors, V, is:" << endl << V << endl << endl;

    for (int i = 0; i < this->_numItems; ++i)
    {
        auto t = std::make_shared<DataNode>();
        t->id = i;
        for (int o = 0; o < order; ++o)
        {
            double v = (o < this->_numItems) ? V(i, o) : 0.0;
            t->dataSet.push_back(v);
        }
        ret.push_back(t);
    }

    return ret;
}

