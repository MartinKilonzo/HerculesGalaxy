#include "TestCSVReader.h"
#include "database/CSVReader.h"
#include <vector>
#include <iostream>
using namespace std;

/* File Loading */
void TestCSVReader::loadGrantsExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Grants_expanded.csv");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadGrantsClinicalFundingFile() {
  CSVReader reader("../Project Information/Sample Data/GrantsClinicalFunding_sample.csv");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Presentations_expanded.csv");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsFile() {
  CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadProgramTeachingExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadNoFile() {
  CSVReader reader;
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() == 0);
}
void TestCSVReader::loadMissingFile() {
  CSVReader reader("MISSING FILE");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() == 0);
}
void TestCSVReader::loadNonCSV() {
  CSVReader reader("../README.md");
  vector<string> header = reader.getHeaders();
  QVERIFY(header.size() == 0);
}

/* File Parsing */
void TestCSVReader::getPresentationsData() {
  CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
  vector<vector<string> > all_data = reader.getData();
  QVERIFY(all_data.size() != 0);
}
void TestCSVReader::getProgramTeachingExpandedData() {
  CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
  vector<vector<string> > all_data = reader.getData();
  QVERIFY(all_data.size() != 0);
}
void TestCSVReader::getNoFileData() {
  CSVReader reader("MISSING FILE");
  vector<vector<string> > all_data = reader.getData();
  QVERIFY(all_data.size() == 0);
}
void TestCSVReader::getNonCSVData() {
  CSVReader reader("../README.md");
  vector<vector<string> > all_data = reader.getData();
  QVERIFY(all_data.size() == 0);
}

/* Date Parsing */
void TestCSVReader::parseMDYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("March 31, 2016");
  QVERIFY(year == 2016);
}
void TestCSVReader::parseDMYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("31 March, 2016");
  QVERIFY(year == 2016);
}
void TestCSVReader::parseYMDDateString() {
  CSVReader reader;
  int year = reader.parseDateString("2016, March 31");
  QVERIFY(year == 2016);
}
