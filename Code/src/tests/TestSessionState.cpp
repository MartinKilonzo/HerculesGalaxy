#include "TestSessionState.h"

/* File Saving and Loading */

void TestSessionState::testFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.save_file(0, "test/File/path.csv");
    QVERIFY(session.save_session_state());
}
void TestSessionState::testFileLoad() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.load_session_state();
    QCOMPARE(session.load_file(0), QString("test/File/path.csv"));
}

void TestSessionState::testStaggeredFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.save_file(4, "test/File/path.csv");
    QVERIFY(session.save_session_state());
}

void TestSessionState::testStaggeredFileLoad() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.load_session_state();
    bool flag = true;
    for (int i = 0; i < 5; i++) {
        QString filePath = session.load_file(i);
        if (i == 4 && filePath != "test/File/path.csv") {
            flag = false;
            break;
        }
        else if (filePath != "") {
            flag = false;
            break;
        }
    }
    QVERIFY(flag);
}

void TestSessionState::testMultipleFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    for (int i = 0; i < 12; i++) {
        session.save_file(i, "test/File/path.csv");
    }
    QVERIFY(session.save_session_state());
}

void TestSessionState::testMultipleFileLoad() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.load_session_state();
    bool flag = true;
    for (int i = 0; i < 12; i++) {
        QString filePath = session.load_file(i);
        if (filePath != "test/File/path.csv") {
            flag = false;
            break;
        }
    }
    QVERIFY(flag);
}

void TestSessionState::testMultipleStaggeredFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.save_file(0, "test/File/path.csv");
    session.save_file(4, "test/File/path.csv");
    session.save_file(7, "test/File/path.csv");
    QVERIFY(session.save_session_state());
}

void TestSessionState::testMultipleStaggeredFileLoad() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.load_session_state();
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        QString filePath = session.load_file(i);
        if ((i == 0 || i == 4 || i == 7) && filePath != "test/File/path.csv") {
            flag = false;
            break;
        }
        else if (filePath.count() != 0) {
            flag = false;
            break;
        }
    }
    QVERIFY(flag);
}

void TestSessionState::testSaveToMissingFile() {
    SessionState session = SessionState("../Project Information/TestData/missingTest.dat");
    QVERIFY(session.save_session_state());
}

void TestSessionState::testLoadFromMissingFile() {
    SessionState session = SessionState("../Project Information/TestData/missingTestFile.dat");
    QVERIFY(session.load_session_state());
}

/* Date Range Saving and Loading */
void TestSessionState::testDateRangeSave() {
    SessionState session = SessionState("../Project Information/TestData/testDate.bat");
    QDate startDate = QDate(2014, 2, 7);
    QDate endDate = QDate(2016, 1, 13);
    session.save_start_date(startDate);
    session.save_end_date(endDate);
    QVERIFY(session.save_session_state());
}
void TestSessionState::testDateRangeLoad() {
    SessionState session = SessionState("../Project Information/TestData/testDate.bat");
    session.load_session_state();
    QDate startDate = session.load_start_date();
    QDate endDate = session.load_end_date();
    bool flag = false;
    if (startDate == QDate(2014, 2, 7) && endDate == QDate(2016, 1, 13)) flag = true;
    QVERIFY(flag);
}
void TestSessionState::testMissingDateRangeSave() {
  SessionState session = SessionState("../Project Information/TestData/missingTestDate.bat");
  QVERIFY(session.save_session_state());
}
void TestSessionState::testMissingDateRangeLoad() {
  SessionState session = SessionState("../Project Information/TestData/missingTestDate.bat");
  session.load_session_state();
  QDate startDate = session.load_start_date();
  QDate endDate = session.load_end_date();
  bool flag = false;
  if (startDate == QDate(1950, 1, 1) && endDate == QDate::currentDate()) flag = true;
  QVERIFY(flag);
}
