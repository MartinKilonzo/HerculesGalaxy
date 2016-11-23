#include "ui_ErrorEditDialog.h"
#include "ErrorEditDialog.h"

#include <QTableWidgetSelectionRange>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>
#include <QBrush>
#include <QColor>
#include <QAbstractButton>
#include <QMessageBox>
#include <iostream>

using namespace std;
/*
 * Load data contained in the errors vector into a QWidgetTable
 *
 * Fields will be marked red and editable if they are a mandatory field
 *
 * Otherwise all other fields will not be editable.
 *
 * Clicking Save in the dialog will return the corrected entries to the main
 * program through the errors parameter.
 *
 * If not all marked fields are edited
 * then a warning message will be displayed.
 *
 * If cancel is clicked all errors
 * are discarded.
 */



ErrorEditDialog::ErrorEditDialog(QWidget *parent,
                                 std::vector<std::vector<std::string>*>& errors,
                                 std::vector<std::string>& headers,
                                 std::vector<std::string>& mandatory) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    //all errors
    errorList(errors),
    //all headers
    headerList(headers),
    mandatoryList(mandatory),
    ui(new Ui::ErrorEditDialog)
{
    ui->setupUi(this);
    //how many rows
    ui->tableWidget->setRowCount((int) errors.size());
    //how many columns
    ui->tableWidget->setColumnCount((int) headers.size());

    QStringList listHeaders;
    for (int i = 0; i < (int) headers.size(); i++) {
        //gets it into a string
        listHeaders << headers[i].c_str();
    }
    //put the strings in table
    ui->tableWidget->setHorizontalHeaderLabels(listHeaders);
    QTableWidgetItem* item;
    QBrush brush(QColor(255, 0, 0, 100));
    QBrush purple(QColor(200,4,5,150));


    std::vector<std::vector<std::string>*>::iterator it;
    int row = 0;
    for (it = errors.begin(); it != errors.end(); it++) {
        for (int col = 0; col < (int) headers.size() && col < (int) (*it)->size(); col++) {
            item = new QTableWidgetItem();
            Qt::ItemFlags flag = item->flags();
            item->setFlags(Qt::ItemIsSelectable);
            item->setText((*it)->at(col).c_str());
            for (int i = 0; i < (int) mandatory.size(); i++) {
                //if it is empty
                if (mandatory[i].compare(headers.at(col)) == 0
                        && (*it)->at(col).compare("") == 0) {
                    item->setBackground(purple);
                    item->setFlags(flag);
                    //ui->tableWidget->horizontalHeaderItem( 0 )->setText( "Last" );
                }
            }
            //set the item
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }


}

//Clean up allocated memory for the table items
ErrorEditDialog::~ErrorEditDialog()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            delete ui->tableWidget->item(i,j);
        }
    }
    delete ui;
}

//Save the new data entered by the user via the error reference var
void ErrorEditDialog::saveData() {
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidget->columnCount() && col < (int) errorList[row]->size(); col++) {
            std::vector<std::string>::iterator it = errorList[row]->begin()+col;
            if (errorList[row]->at(col).compare("") == 0) {
                it = errorList[row]->erase(it);
                errorList[row]->insert(it, ui->tableWidget->item(row, col)->text().toStdString());
            }
        }
    }
    accept();
}


static int b = 0;

void ErrorEditDialog::on_prev_clicked()
{
    double balance[100000];
    double balance2[100000];

    //for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidget->columnCount() && col < (int) errorList[row]->size(); col++) {
            std::vector<std::string>::iterator it = errorList[row]->begin()+col;
            if (errorList[row]->at(col).compare("") == 0) {
                static int a = 0;
                balance [a] = row;
                balance2 [a] = col;
                a = a+1;

                it = errorList[row]->erase(it);
                errorList[row]->insert(it, ui->tableWidget->item(row, col)->text().toStdString());
            }
        }
    }
    QTableWidgetSelectionRange range = QTableWidgetSelectionRange(balance[b-2],balance2[b-2],balance[b-2],balance2[b-2]);
    ui->tableWidget->setRangeSelected(range,true);
    QTableWidgetSelectionRange range2 = QTableWidgetSelectionRange(balance[b-1],balance2[b-1],balance[b-1],balance2[b-1]);
    ui->tableWidget->setRangeSelected(range2,false);

    b = b-1;
    //check if mandatory fields have been filled
    /*QBrush brush(QColor(255, 0, 0, 100));
    std::vector<std::vector<std::string>*>::iterator i;
    int i = errors.begin();
    if (mandatory[i].compare(headers.at(col)) == 0 && (*it)->at(col).compare("") == 0) {
        item->setBackground(brush);
        i++;*/
       // item->setFlags(flag);
        //ui->tableWidget->horizontalHeaderItem( 0 )->setText( "Last" );
    //}


    /*for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int j = 0; j < (int) mandatoryList.size(); j++) {
            std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[j]);
            int col = it - headerList.begin();
            QTableWidgetItem* item = ui->tableWidget->item(row, col);

        }
    }*/






    /*static int count = 0;
            std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[count]);
            int col = it - headerList.begin();
         //   int col = headerList.end() - it;
            cout<<col<<endl;
            //int col = 1;
            //QTableWidgetItem* item = ui->tableWidget->item(row, col);
            //QTableWidgetSelectionRange range = QTableWidgetSelectionRange(1,7,1,7);
//QColor(52, 14, 22, 155)
          //  QTableWidgetSelectionRange range = QTableWidgetSelectionRange(count,col,count,col);

            //ui->tableWidget->setRangeSelected(range,true);

            QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);

            ui->tableWidget->setRangeSelected(range,true);

            if (count>0)
                   // int col2 = it - headerList.begin();
                    QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);
                    ui->tableWidget->setRangeSelected(range,false);

            count = count + 1;*/





          //  cout<<count<<endl;
}


void ErrorEditDialog::on_next_clicked()
{
    //static int b = 0;
    double balance[100000];
    double balance2[100000];

    //for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidget->columnCount() && col < (int) errorList[row]->size(); col++) {
            std::vector<std::string>::iterator it = errorList[row]->begin()+col;
            if (errorList[row]->at(col).compare("") == 0) {
                static int a = 0;
                balance [a] = row;
                balance2 [a] = col;
                a = a+1;

                it = errorList[row]->erase(it);
                errorList[row]->insert(it, ui->tableWidget->item(row, col)->text().toStdString());
            }
        }
    }
    QTableWidgetSelectionRange range = QTableWidgetSelectionRange(balance[b],balance2[b],balance[b],balance2[b]);
    ui->tableWidget->setRangeSelected(range,true);
    QTableWidgetSelectionRange range2 = QTableWidgetSelectionRange(balance[b-1],balance2[b-1],balance[b-1],balance2[b-1]);
    ui->tableWidget->setRangeSelected(range2,false);

    b = b+1;



    //bool search = true;
    //check if mandatory fields have been filled
    /*QStringList listHeaders;
    for (int i = 0; i < (int) headers.size(); i++) {
        //gets it into a string
        listHeaders << headers[i].c_str();
    }
    std::vector<std::vector<std::string>*>::iterator it;
    int row = 0;
    for (it = errors.begin(); it != errors.end(); it++) {
        for (int col = 0; col < (int) headers.size() && col < (int) (*it)->size(); col++) {
            item = new QTableWidgetItem();
            Qt::ItemFlags flag = item->flags();
            item->setFlags(Qt::ItemIsSelectable);
            item->setText((*it)->at(col).c_str());
            for (int i = 0; i < (int) mandatory.size(); i++) {
                //if it is empty
                if (mandatory[i].compare(headers.at(col)) == 0
                        && (*it)->at(col).compare("") == 0) {
                   // item->setBackground(brush);
                   // item->setFlags(flag);
                    //ui->tableWidget->horizontalHeaderItem( 0 )->setText( "Last" );
                }
            }
            //set the item
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }*/

    //search through row
  //  for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        //search through column
//        for (int j = 0; j < (int) mandatoryList.size(); j++) {
      //  int count;





    /*
    static int count = 0;

    std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[count]);

    int col = it - headerList.begin();
    QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);
  //  QTableWidgetSelectionRange range2 = QTableWidgetSelectionRange(0,col,0,col);
    ui->tableWidget->setRangeSelected(range,true);
            count = count + 1;
            */





      //      int col2 = it - headerList.begin();
        //    QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col2,0,col2);
          //  ui->tableWidget->setRangeSelected(range2,false);

         //   int col = it - headerList.begin();
            //cout<<col<<endl;
            //int col = 1;
            //QTableWidgetItem* item = ui->tableWidget->item(row, col);
            //QTableWidgetSelectionRange range = QTableWidgetSelectionRange(1,7,1,7);
//QColor(52, 14, 22, 155)
          //  QTableWidgetSelectionRange range = QTableWidgetSelectionRange(count,col,count,col);
            //ui->tableWidget->setRangeSelected(range,true);
            //ui->tableWidget->setRangeSelected(range,true);
            //QTableWidgetSelectionRange range2 = QTableWidgetSelectionRange(0,col+1,0,col+1);
          //  QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);
          //  QTableWidgetSelectionRange range2 = QTableWidgetSelectionRange(0,col,0,col);
           // ui->tableWidget->setRangeSelected(range,true);
            //ui->tableWidget->setRangeSelected(range2,true);
            //QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);

          //  if (count>0)
                   // int col2 = it - headerList.begin();
            //        QTableWidgetSelectionRange range = QTableWidgetSelectionRange(0,col,0,col);
                    //ui->tableWidget->setRangeSelected(range,false);

           // count = count + 1;
        //    cout<<count<<endl;

           // ui->tableWidget->setRangeSelected((1,1,10,2,true);

            //QTableWidgetSelectionRange range = QTableWidgetSelectionRange(1,1,1,1);
            //ui->tableWidget->setRangeSelected(range,true);
            //range.QTableWidgetSelectionRange(1,1,2,2);
            //range.QTableWidgetSelectionRange(1, 1, 2, 2);

            //ui->tableWidget->setRangeSelected(range,true);
                    //QTableWidgetSelectionRange(1, 1, 2, 2);

            //ui->tableWidget->setItem(row, col, item);
            //ui->tableWidget->setItem(row, col, item);


            //setRangeSelected(const QTableWidgetSelectionRange &1, true);

            //ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            //ui->tableWidget->selectRow(0);

            //comparison
            //if (item->text().compare("") == 0) {
             //   QMessageBox::critical(this, "Error", "Mandatory fields are still empty.");
             //   search = false;
           // }
    //    }
    //}
    //if (search) {
      //  saveData();
    //}
}


void ErrorEditDialog::on_save_clicked()
{
    bool search = true;
    //check if mandatory fields have been filled
    for (int row = 0; row < ui->tableWidget->rowCount() && search; row++) {
        for (int j = 0; j < (int) mandatoryList.size() && search; j++) {
            std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[j]);
            int col = it - headerList.begin();
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item->text().compare("") == 0) {
                QMessageBox::critical(this, "Error", "Mandatory fields are still empty.");
                search = false;
            }
        }
    }
    if (search) {
        saveData();
    }
}

void ErrorEditDialog::on_cancel_clicked()
{
    reject();
}
