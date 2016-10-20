#include "TestCSVReader.h"
#include "database/CSVReader.h"
#include <vector>
#include <iostream>
using namespace std;

void TestCSVReader::loadGrantsExpandedFile(){
    CSVReader reader("../Project Information/Sample Data/Grants_expanded.csv");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() != 0);
}
void TestCSVReader::loadGrantsClinicalFundingFile(){
    CSVReader reader("../Project Information/Sample Data/GrantsClinicalFunding_sample.csv");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsExpandedFile(){
    CSVReader reader("../Project Information/Sample Data/Presentations_expanded.csv");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsFile(){
    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() != 0);
}
void TestCSVReader::loadProgramTeachingExpandedFile(){
    CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() != 0);
}
void TestCSVReader::loadNoFile(){
    CSVReader reader("NO FILE");
    vector<string> header = reader.getHeaders();
    QVERIFY(header.size() == 0);
}

void TestCSVReader::getPresentationsData(){
    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
    vector< vector<string> > all_data = reader.getData();
    QVERIFY(all_data.size() != 0);
}

void TestCSVReader::getProgramTeachingExpandedData(){
    CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
    vector< vector<string> > all_data = reader.getData();
    QVERIFY(all_data.size() != 0);
}
