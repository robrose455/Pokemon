#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class FileManager
{
public:

    FileManager(string fileName, string name);

    vector<string> ReadStats();

private:

    string fileName_;
    string name_;

};

