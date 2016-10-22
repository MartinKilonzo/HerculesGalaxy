#include <QtTest/QtTest>
#include "database/CSVReader.h"
#include "gui/piechartwidget.h"
#include "gui/mainwindow.h"

class TestGraph: public QObject
{
    Q_OBJECT
private slots:
    void testGraph();
};
