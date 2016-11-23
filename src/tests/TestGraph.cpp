#include "TestGraph.h"

void TestGraph::testGraphLegacy()
{
    CSVReader *c = new CSVReader();
    std::vector<std::vector<std::string>> empty;

    (*c).loadCSV("../Project Information/Sample Data/GrantsClinicalFunding_sample.csv");
    QVERIFY((*c).getData() != empty);
    (*c).loadCSV("../Project Information/Sample Data/Presentations_sample.csv");
    QVERIFY((*c).getData() != empty);
    (*c).loadCSV("../Project Information/Sample Data/Publications_sample.csv");
    QVERIFY((*c).getData() != empty);
    (*c).loadCSV("../Project Information/Sample Data/Teaching_sample.csv");
    QVERIFY((*c).getData() != empty);
}
void TestGraph::testGraphNew()
{
    CSVReader *c = new CSVReader();
    std::vector<std::vector<std::string>> empty;

    (*c).loadCSV("../Project Information/New Sample Data/Publications_expanded.csv");
    QVERIFY((*c).getData() != empty);
}
