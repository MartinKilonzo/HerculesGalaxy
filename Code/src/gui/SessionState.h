#ifndef SESSIONSTATE_H
#define SESSIONSTATE_H

#include <string>
#include <iostream>
#include <vector>
#include <QString>
#include <QDate>
#include <QFile>
#include <QIODevice>
#include <QDataStream>

using namespace std;

typedef std::vector<std::vector<std::string>*> errors;

class SessionState {
        QDate startDate;
        QDate endDate;
        QString fileName;
        std::vector<string> filePaths;
        void load_filter();
        void load_view();
        void save_filter();
        void save_view();
public:
        SessionState(string);
        QDate load_start_date();
        QDate load_end_date();
        QString load_file(int);
        errors load_error_fixes(int);
        bool load_session_state();

        void save_start_date(QDate);
        void save_end_date(QDate);
        void save_file(int, QString);
        void save_error_fixes(int, errors);
        bool save_session_state();

        string toString();
};

#endif // SESSIONSTATE_H
