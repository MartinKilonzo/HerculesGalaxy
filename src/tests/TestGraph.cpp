#include "TestGraph.h"

void TestGraph::testGraph()
{
    CSVReader *c = new CSVReader();
    std::vector<std::vector<std::string>> empty;
    (*c).loadCSV("../Project Information/Sample Data/Teaching_sample.csv");
    QVERIFY((*c).getData() != empty);
}
