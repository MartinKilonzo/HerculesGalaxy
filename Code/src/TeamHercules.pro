#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T14:49:31
#
#-------------------------------------------------

QT              += core gui
QT              += testlib
CONFIG          += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TARGET = TeamHercules
TEMPLATE = app

DISTFILES += \
    TeamHercules.pro.user \
    database/TestCSVReader.h.old \
    database/TestCSVReader.cpp.old

HEADERS += \
    gui/CustomSort.h \
    gui/ErrorEditDialog.h \
    gui/piechartwidget.h \
    gui/mainwindow.h \
    database/CSVReader.h \
    database/RecordsManager.h \
    database/QSortListIO.h\
    datamodel/TreeItem.h \
    datamodel/TreeModel.h \
    datamodel/PresentationTreeModel.h \
    datamodel/PublicationTreeModel.h \
    datamodel/GrantFundingTreeModel.h \
    datamodel/TeachingTreeModel.h \
    gui/qcustomplot.h \
    tests/TestCSVReader.h \
    tests/TestRecordsManager.h \
    tests/TestGraph.h \
    gui/SessionState.h \
    tests/TestSessionState.h \
    tests/TestDivision.h

SOURCES += \
    gui/CustomSort.cpp \
    gui/ErrorEditDialog.cpp \
    gui/piechartwidget.cpp \
    gui/main.cpp \
    gui/mainwindow.cpp \
    database/CSVReader.cpp \
    database/RecordsManager.cpp \
    database/QSortListIO.cpp \
    datamodel/TreeItem.cpp \
    datamodel/TreeModel.cpp \
    datamodel/PresentationTreeModel.cpp \
    datamodel/PublicationTreeModel.cpp \
    datamodel/GrantFundingTreeModel.cpp \
    datamodel/TeachingTreeModel.cpp \
    gui/qcustomplot.cpp \
    tests/TestCSVReader.cpp \
    tests/TestRecordsManager.cpp \
    gui/SessionState.cpp \
    tests/TestGraph.cpp \
    tests/TestSessionState.cpp \
    tests/TestDivision.cpp

FORMS += \
    gui/customsort.ui \
    gui/mainwindow.ui \
    gui/ErrorEditDialog.ui

RESOURCES += \
    images.qrc
