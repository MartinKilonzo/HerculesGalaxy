#ifndef TESTRECORDSMANAGER_H
#define TESTRECORDSMANAGER_H

#include <QObject>
#include <QtTest/QtTest>

class TestRecordsManager: public QObject
{
        Q_OBJECT
private slots:
        /* Constructor */
        void testConstructor();

        /* Find Records */
        void testFindRecord();
        void testFindRecordInvalidYear();
        void testFindRecordsInRange();
        void testFindRecordsInInvalidRange();

        /* Get Header Indices */
        void testGetHeaderIndex();
        void testGetInvalidHeaderIndex();
};

#endif // TESTRECORDSMANAGER_H
