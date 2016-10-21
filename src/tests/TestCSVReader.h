#ifndef TESTCSVREADER_H
#define TESTCSVREADER_H

#include <QObject>
#include <QtTest/QtTest>

class TestCSVReader: public QObject
{
        Q_OBJECT
private slots:
        /* File Loading */
        void loadGrantsExpandedFile();
        void loadGrantsClinicalFundingFile();
        void loadPresentationsExpandedFile();
        void loadPresentationsFile();
        void loadProgramTeachingExpandedFile();
        void loadNoFile();
        void loadMissingFile();
        void loadNonCSV();

        /* File Parsing */
        void getPresentationsData();
        void getProgramTeachingExpandedData();
        void getNoFileData();
        void getNonCSVData();
        void getSingleCommaData();
        void getMultipleCommaData();
        void getObscureCharacterData();

        /* Date Parsing */
        void parseTextMDYDateString();
        void parseTextDMYDateString();
        void parseTextYMDDateString();
        void parseNumberMDYDateString();
        void parseNumberDMYDateString();
        void parseNumberYMDDateString();
};

#endif // TESTCSVREADER_H
