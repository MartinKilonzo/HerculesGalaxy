#include "TestRecordsManager.h"
#include "database/CSVReader.h"
#include "database/RecordsManager.h"
#include <vector>
#include <iostream>
#include <QString>
#include <QDebug>
using namespace std;

typedef BasicRecord BasicRecord;

CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");

/* Constructor */
void TestRecordsManager::testConstructor() {
  RecordsManager rManager(&reader.getHeaders());
  BasicRecord headers = rManager.getHeaders();
  QVERIFY(headers.size() != 0);
}

/* Find Records */
void TestRecordsManager::testFindRecord() {
  RecordsManager rManager(&reader.getHeaders());
  std::vector<BasicRecord*> count = rManager.findRecord(2008);
  // qInfo(std::to_string(count.size()).c_str());
  QVERIFY(count.size() != 0);
}
void TestRecordsManager::testFindRecordInvalidYear() {
  RecordsManager rManager(&reader.getHeaders());
  std::vector<BasicRecord*> count = rManager.findRecord(-1940);
  // qInfo(std::to_string(count.size()).c_str());
  QVERIFY(count.size() == 0);
}
void TestRecordsManager::testFindRecordsInRange() {
  RecordsManager rManager(&reader.getHeaders());
  std::vector<BasicRecord*> count = rManager.findRecordsInRange(2000, 2010);
  // qInfo(std::to_string(count.size()).c_str());
  QVERIFY(count.size() != 0);
}
void TestRecordsManager::testFindRecordsInInvalidRange() {
  RecordsManager rManager(&reader.getHeaders());
  std::vector<BasicRecord*> count = rManager.findRecordsInRange(2000, -2010);
  // qInfo(std::to_string(count.size()).c_str());
  QVERIFY(count.size() == 0);
}

/* Get Header Indices */
void TestRecordsManager::testGetHeaderIndex() {
  RecordsManager rManager(&reader.getHeaders());
  QCOMPARE(rManager.getHeaderIndex("Member Name"), 4);
}
void TestRecordsManager::testGetInvalidHeaderIndex() {
  RecordsManager rManager(&reader.getHeaders());
  QVERIFY(rManager.getHeaderIndex("INVALID HEADER") < 0);
}
