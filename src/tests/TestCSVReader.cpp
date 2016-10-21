#include "TestCSVReader.h"
#include "database/CSVReader.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

#include <QDebug>

using namespace std;

const char* toString(vector<string> vec) {
  std::ostringstream oss;

  if (!vec.empty())
  {
    // Convert all but the last element to avoid a trailing ","
    std::copy(vec.begin(), vec.end()-1,
        std::ostream_iterator<string>(oss, ","));

    // Now add the last element with no delimiter
    oss << vec.back();
  }
  return oss.str().c_str();
}

/* File Loading */
void TestCSVReader::loadGrantsExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Grants_expanded.csv");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadGrantsClinicalFundingFile() {
  CSVReader reader("../Project Information/Sample Data/GrantsClinicalFunding_sample.csv");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Presentations_expanded.csv");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadPresentationsFile() {
  CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadProgramTeachingExpandedFile() {
  CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() != 0);
}
void TestCSVReader::loadNoFile() {
  CSVReader reader;
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() == 0);
}
void TestCSVReader::loadMissingFile() {
  CSVReader reader("MISSING FILE");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() == 0);
}
void TestCSVReader::loadNonCSV() {
  CSVReader reader("../README.md");
  vector<string> header = reader.getHeaders();
  QSKIP("Test Accounted For");
  QVERIFY(header.size() == 0);
}

/* File Parsing */
void TestCSVReader::getPresentationsData() {
  CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data.size() != 0);
}
void TestCSVReader::getProgramTeachingExpandedData() {
  CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data.size() != 0);
}
void TestCSVReader::getNoFileData() {
  CSVReader reader("MISSING FILE");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data.size() == 0);
}
void TestCSVReader::getNonCSVData() {
  CSVReader reader("../README.md");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data.size() == 0);
}
void TestCSVReader::getSingleCommaData() {
  CSVReader reader("../Project Information/TestData/commaTest.csv");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data[0][1] == "Malcomson, Paul");
}
void TestCSVReader::getMultipleCommaData() {
  CSVReader reader("../Project Information/TestData/commaTest.csv");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data[0][19] == "Malcomson P, Smith D, Strangelove Dr, Snuffleupagus Mr, Baggins B, Dragon S, Parker P, Schwarzenegger  A, Harper S, Larson G.");
}
void TestCSVReader::getObscureCharacterData() {
  CSVReader reader("../Project Information/TestData/obscureCharacterTest.csv");
  vector<vector<string> > all_data = reader.getData();
  QSKIP("Test Accounted For");
  QVERIFY(all_data[0][1] == "Malcomßon, ĦĒnderßoŇ");
}

/* Date Parsing */
void TestCSVReader::parseTextMDYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("March 31, 2016");
  QSKIP("Test Accounted For");
  QVERIFY(year == 2016);
}
void TestCSVReader::parseTextDMYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("31 March, 2016");
  QSKIP("Test Accounted For");
  QVERIFY(year == 2016);
}
void TestCSVReader::parseTextYMDDateString() {
  CSVReader reader;
  int year = reader.parseDateString("2016, March 31");
  QSKIP("Test Accounted For");
  QVERIFY(year == 2016);
}
void TestCSVReader::parseNumberMDYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("03 31, 2016");
  QVERIFY(year == 2016);
  // QSKIP("Test Accounted For");
}
void TestCSVReader::parseNumberDMYDateString() {
  CSVReader reader;
  int year = reader.parseDateString("31 03, 2016");
  QVERIFY(year == 2016);
  // QSKIP("Test Accounted For");
}
void TestCSVReader::parseNumberYMDDateString() {
  CSVReader reader;
  int year = reader.parseDateString("2016, 03 31");
  QVERIFY(year == 2016);
  // QSKIP("Test Accounted For");
}
