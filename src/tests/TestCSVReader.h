#ifndef TESTCSVREADER_H
#define TESTCSVREADER_H

#include <QObject>
#include <QtTest/QtTest>

class TestCSVReader: public QObject
{
    Q_OBJECT
private slots:
    void loadGrantsExpandedFile();
    void loadGrantsClinicalFundingFile();
    void loadPresentationsExpandedFile();
    void loadPresentationsFile();
    void loadProgramTeachingExpandedFile();
    void loadNoFile();
    void getPresentationsData();
    void getProgramTeachingExpandedData();
};

#endif // TESTCSVREADER_H
