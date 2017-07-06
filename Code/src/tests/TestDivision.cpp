#include "TestDivision.h"

void TestDivision::getDivisionTeaching() {
    CSVReader reader("../Project Information/New Sample Data/Program_Teaching_expanded.csv");
    vector<string> header = reader.getHeaders();
    bool flag = false;
    int i = 0;
    while(i < header.size() && flag == false) {
        if (header[i] == "Division") {
            flag = true;
        }
        else {
            i++;
        }
    }
    QVERIFY(flag);
}

void TestDivision::getDivisionGrants() {

    CSVReader reader("../Project Information/New Sample Data/Grants_expanded.csv");
    vector<string> header = reader.getHeaders();
    bool flag = false;
    int i = 0;
    while(i < header.size() && flag == false) {
        if (header[i] == "Division") {
            flag = true;
        }
        else {
            i++;
        }
    }
    QVERIFY(flag);
}

void TestDivision::getDivisionPres() {

    CSVReader reader("../Project Information/New Sample Data/Presentations_expanded.csv");
    vector<string> header = reader.getHeaders();
    bool flag = false;
    int i = 0;
    while(i < header.size() && flag == false) {
        if (header[i] == "Division") {
            flag = true;
        }
        else {
            i++;
        }
    }
    QVERIFY(flag);
}

void TestDivision::getDivisionPubs() {

    CSVReader reader("../Project Information/New Sample Data/Publications_expanded.csv");
    vector<string> header = reader.getHeaders();
    bool flag = false;
    int i = 0;
    while(i < header.size() && flag == false) {
        if (header[i] == "Division") {
            flag = true;
        }
        else {
            i++;
        }
    }
    QVERIFY(flag);
}
