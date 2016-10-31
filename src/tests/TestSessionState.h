#ifndef TESTSESSIONSTATE_H
#define TESTSESSIONSTATE_H

#include <QObject>
#include <QString>
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
};

#endif // TESTSESSIONSTATE_H
