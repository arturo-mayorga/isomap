#include <iostream>
#include <memory>
#include "projpipeline.h"
#include "euclideandistanceprocessor.h"
using namespace std;


int main()
{
    int nodeCount = 0;

    cin >> nodeCount;

    ProjPipeline pipe;
    pipe.setDistanceProcessor(make_shared<EuclideanDistanceProcessor>());

    for (int i = 0; i < nodeCount; ++i)
    {
        int dataPointCount = 0;
        cin >> dataPointCount;
        auto newNode = make_shared<DataNode>();
        newNode->id = i;
        for (int j = 0; j < dataPointCount; ++j)
        {
            double dp = 0;
            cin >> dp;
            newNode->dataSet.push_back(dp);
        }

        pipe.addDataNode(newNode);
    }

    pipe.update();

    auto decomp = pipe.getEigenDecomp(5);

    cout << "Number of results: " << decomp.size() << endl;

    for (auto dn : decomp)
    {
        int id = dn->id;
        cout << id << ": ";

        auto dataSet = dn->dataSet;
        for (auto d : dataSet)
        {
            cout << d << ", ";
        }
        cout << endl;
    }

    return 0;
}



