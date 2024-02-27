//
// Created by bozhi on 2024/1/7.
//

#ifndef ZHUIDA_FILE_H
#define ZHUIDA_FILE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class string_1:public string
{
public:
    string_1();
    string_1(const char* a);
    string_1(const string& a);
    string_1(const string_1& a);
    string_1(const char& a);

public:
    void operator=(const string_1& str);
    void operator=(const char& str);
    bool operator==(const char& a);
    bool operator==(const char* a);
    bool operator==(const string& a);
    bool operator!=(const char& a);
    bool operator!=(const char* a);
    bool operator!=(const string& a);
};

class file
{
public:
    string_1 mode;
    const string& address;
    fstream f;

public:
    file(const string& address1, const string& mode1);
    file(const string& address1, const char& mode1);
    ~file();

public:
    void write(const string& content);
    string read();
    string getline();
};

#endif //ZHUIDA_FILE_H
