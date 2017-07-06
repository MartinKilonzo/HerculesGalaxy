#ifndef TESTSESSIONSTATE_H
#define TESTSESSIONSTATE_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QTest>

#include "gui/SessionState.h"

using namespace std;

class TestSessionState: public QObject
{
        Q_OBJECT
private slots:
        /* File Saving and Loading */
        void testFileSave();
        void testFileLoad();
        void testStaggeredFileSave();
        void testStaggeredFileLoad();
        void testMultipleFileSave();
        void testMultipleFileLoad();
        void testMultipleStaggeredFileSave();
        void testMultipleStaggeredFileLoad();
        void testSaveToMissingFile();
        void testLoadFromMissingFile();

        /* Date Range Saving and Loading */
        void testDateRangeSave();
        void testDateRangeLoad();
        void testMissingDateRangeSave();
        void testMissingDateRangeLoad();
};

#endif // TESTSESSIONSTATE_H
