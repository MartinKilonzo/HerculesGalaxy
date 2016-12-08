#include "TestDivision.h"

void TestDivision::getDivisionTeaching() {
    CSVReader reader("../Project Information/Sample Data/Program_Teaching_expanded.csv");
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
}

void TestDivision::getDivisionGrants() {

    CSVReader reader("../Project Information/Sample Data/Grants_expanded.csv");
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
}

void TestDivision::getDivisionPres() {

    CSVReader reader("../Project Information/Sample Data/Presentations_sample.csv");
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
}

void TestDivision::getDivisionPubs() {

    CSVReader reader("../Project Information/Sample Data/Publications_sample.csv");
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
}
