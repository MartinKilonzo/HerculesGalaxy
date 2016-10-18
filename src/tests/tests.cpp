#include "tests/tests.h"

void TestQString::toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

/*void TestGui::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}*/
