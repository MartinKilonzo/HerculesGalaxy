#include "SessionState.h"



SessionState::SessionState() {
    std::vector<string> filePaths;
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

void SessionState::save_file(int index, QString path) {
    std::cout << "Saving File ..." << std::endl;
    std::cout << "Saving: " << index << "\t" << path.toStdString() << std::endl;
    if (filePaths.size() <= index) {
        std::cout << "Resize!" << std::endl;
        filePaths.resize(index, "");
        filePaths.push_back(path.toStdString());
    }
    else
        filePaths[index] = path.toStdString();
    std::cout << "Files:" << std::endl << toString() << std::endl;
    std::cout << "... Saving File" << std::endl;

}

void SessionState::save_filter() {

}

void SessionState::save_view() {

}

void SessionState::load_session_state() {
    std::cout << "Loading ..." << std::endl;
    QFile file("session.dat");
    if (file.exists()) {
        file.open(QIODevice::ReadOnly);
        QDataStream qds(&file);
        qint32 size;
        qds >> size;
        std::cout << "Size: " << size << std::endl;
        for (int i = 0; i < size; i++) {
            QString item;
            qds >> item;
            std::cout << "Reading: " << i << "\t" << item.toStdString() << std::endl;
            save_file(i, item);
        }
    }
    std::cout << "... Loading" << std::endl;
}

void SessionState::save_session_state() {
    std::cout << "Saving ..." << std::endl;
    QFile file("session.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream qds(&file);
    qds << (qint32)filePaths.size();
    for (std::vector<string>::iterator itr = filePaths.begin(); itr != filePaths.end(); itr++) {
        std::cout << "Writing: " << *itr << std::endl;
        qds << QString((*itr).c_str());
    }
    std::cout << "... Saving" << std::endl;
}

string SessionState::toString() {
    string str = "";
    for (std::vector<string>::iterator itr = filePaths.begin(); itr != filePaths.end(); itr++) {
        str += *itr + "\n";
    }
    return str;
}
