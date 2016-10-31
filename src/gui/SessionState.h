#include <string>
#include <iostream>
#include <vector>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDataStream>

using namespace std;

class SessionState {
        std::vector<string> filePaths;
        void load_filter();
        void load_view();
        void save_filter();
        void save_view();
public:
        SessionState();
        QString load_file(int);
        void load_session_state();
        void save_file(int, QString);
        void save_session_state();
        string toString();
};
