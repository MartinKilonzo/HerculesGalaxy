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
    QCOMPARE(session.load_file(0), "test/File/path.csv");
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
    for (int i = 0; i < 5) {
        string filePath = session.load_file(i);
        if (i == 4 && filePath != "test/File/path.csv") {
            flag = FALSE;
            break;
        }
        else if (filePath != "") {
            flag = FALSE;
            break;
        }
    }
    QVERIFY(flag);
}

void TestSessionState::testMultipleFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
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
    for (int i = 0; i < 12) {
        string filePath = session.load_file(i);
        if (string != "test/File/path.csv") {
            flag = false;
            break;
        }
    }
    QVERIFY(flag);
}

void TestSessionState::testMultipleStaggeredFileSave() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.save_file(0, "test/File/path.csv");
    session.save_file(4, "test/File/path.csv");
    session.save_file(7, "test/File/path.csv");
    QVERIFY(session.save_session_state());
}

void TestSessionState::testMultipleStaggeredFileLoad() {
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    SessionState session = SessionState("../Project Information/TestData/test.dat");
    session.load_session_state();
    bool flag = true;
    for (int i = 0; i < 8) {
        string filePath = session.load_file(i);
        if ((i == 0 || i == 4 || i == 7) && filePath != "test/File/path.csv") {
            flag = FALSE;
            break;
        }
        else if (filePath != "") {
            flag = FALSE;
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
    QVERIFY(!session.save_session_state());

}
