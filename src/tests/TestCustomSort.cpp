#import <QStringList>

QStringList TestCustomSort::getSortFields(){

   QStringList qString;
   qString << "HI " <<"HELLO";

   QVERIFY (!qString.isEmpty()) ;

   return qString;
}

void TestCustomSort::on_buttonBox_rejected() {
  int finish = 0;
  QVERIFY (finish == 0);
}
