#include <iostream>
#include <stdio.h>
#include <QApplication>
#include <QTreeView>

#include "gui/mainwindow.h"
#include "tests/TestCSVReader.h"
#include "tests/TestRecordsManager.h"
#include "tests/TestGraph.h"
#include "tests/TestSessionState.h"
#include "tests/TestDivision.h"

using namespace std;

int main(int argc, char *argv[]) {
  int test = 1;     /* test off */

  if (test) {
    TestGraph *testGraph = new TestGraph();
    QTest::qExec(testGraph);
    TestCSVReader *testCSVReader = new TestCSVReader();
    QTest::qExec(testCSVReader);
    TestRecordsManager *testRecordsManager = new TestRecordsManager();
    QTest::qExec(testRecordsManager);
    TestSessionState *testSessionState = new TestSessionState();
    QTest::qExec(testSessionState);
    TestDivision *testDivision = new TestDivision();
    QTest::qExec(testDivision);
  }
  else {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
  }
}
