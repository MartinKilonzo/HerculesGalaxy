#include "SessionState.h"



SessionState::SessionState(string newFileName) {
    // set the default start year to be 1950
    startDate = QDate(1950, 1, 1);
    // set the default end date to be today
    endDate = QDate::currentDate();
    fileName = QString(newFileName.c_str());
    std::vector<string> filePaths;
}

QDate SessionState::load_start_date() {
    return startDate;
}
QDate SessionState::load_end_date() {
    return endDate;
}

QString SessionState::load_file(int index) {
    if (index < filePaths.size())
        return QString(filePaths[index].c_str());
    else
        return "";
}

void SessionState::load_filter() {

}

void SessionState::load_view() {

}

bool SessionState::load_session_state() {
    // std::cout << "Loading ..." << std::endl;
    QFile file(fileName);
    if (file.exists()) {
        file.open(QIODevice::ReadOnly);
        QDataStream qds(&file);
        // Read the start date from the file
        qds >> startDate;
        // Read the end date from the file
        qds >> endDate;
        // Read the list size to know how many saved file paths to read
        qint32 size;
        qds >> size;
        // std::cout << "Size: " << size << std::endl;
        for (int i = 0; i < size; i++) {
            QString item;
            qds >> item;
            // std::cout << "Reading: " << i << "\t" << item.toStdString() << std::endl;
            save_file(i, item);
        }
        // std::cout << "... Loading" << std::endl;
        return true;
    }
    else return false;
}

void SessionState::save_start_date(QDate date) {
    startDate = date;
}
void SessionState::save_end_date(QDate date) {
    endDate = date;
}

void SessionState::save_file(int index, QString path) {
    // std::cout << "Saving File ..." << std::endl;
    // std::cout << "Saving: " << index << "\t" << path.toStdString() << std::endl;
    if (filePaths.size() <= index) {
        // std::cout << "Resize!" << std::endl;
        filePaths.resize(index, "");
        filePaths.push_back(path.toStdString());
    }
    else
        filePaths[index] = path.toStdString();
    // std::cout << "Files:" << std::endl << toString() << std::endl;
    // std::cout << "... Saving File" << std::endl;

}

void SessionState::save_filter() {

}

void SessionState::save_view() {

}

bool SessionState::save_session_state() {
    // std::cout << "Saving ..." << std::endl;
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream qds(&file);
    // Write the start date to file
    qds << startDate;
    // Write the end date to file
    qds << endDate;
    // Write the file path size to the file for ease of loading
    qds << (qint32)filePaths.size();
    for (std::vector<string>::iterator itr = filePaths.begin(); itr != filePaths.end(); itr++) {
        // std::cout << "Writing: " << *itr << std::endl;
        qds << QString((*itr).c_str());
    }
    // std::cout << "... Saving" << std::endl;
    if (file.exists()) return true;
    else return false;
}

string SessionState::toString() {
    string str = "";
    for (std::vector<string>::iterator itr = filePaths.begin(); itr != filePaths.end(); itr++) {
        str += *itr + "\n";
    }
    return str;
}
