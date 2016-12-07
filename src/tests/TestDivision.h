#include <QtTest/QtTest>
#include "database/CSVReader.h"
using namespace std;

class TestDivision: public QObject
{
    Q_OBJECT
private slots:
    void getDivisionTeaching();
           void getDivisionGrants();
           void getDivisionPres();
           void getDivisionPubs();
};
