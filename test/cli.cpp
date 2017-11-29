#include <iostream>
#include <memory>
#include <projpipeline.h>
#include <euclideandistanceprocessor.h>
#include <manifolddistanceprocessor.h>
using namespace std;

int main()
{
    vector<double> weightVector;
    int weightCount = 0;
    cin >> weightCount;
    for (int i = 0; i < weightCount; ++i) {
        double weight = 0;
        cin >> weight;
        weightVector.push_back(weight);
    }

    int nodeCount = 0;

    cin >> nodeCount;

    ProjPipeline pipe;
    // pipe.setDistanceProcessor(make_shared<EuclideanDistanceProcessor>());
    pipe.setDistanceProcessor(make_shared<ManifoldDistanceProcessor>());

    for (int i = 0; i < nodeCount; ++i)
    {
        int dataPointCount = 0;
        int id = 0;
        cin >> id;
        cin >> dataPointCount;
        auto newNode = make_shared<DataNode>();
        newNode->id = id;
        for (int j = 0; j < dataPointCount; ++j)
        {
            double dp = 0;
            cin >> dp;

            double weight = 1;

            if (j < weightCount) {
                weight = weightVector[j];
            }

            newNode->dataSet.push_back(dp * weight);
        }

        pipe.addDataNode(newNode);
    }

    pipe.update();

    auto decomp = pipe.getEigenDecomp(2);

    cout << "Number of results: " << decomp.size() << endl;

    for (auto dn : decomp)
    {
        int id = dn->id;
        cout << "['[" << id << "]', ";

        auto dataSet = dn->dataSet;
        for (auto d : dataSet)
        {
            cout << d << ", ";
        }
        cout << "]," <<  endl;
    }

    return 0;
}



