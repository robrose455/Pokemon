#include "FileManager.h"
#include <sstream>


FileManager::FileManager(string fileName, string name)
    : fileName_(fileName), name_(name)
{

}

vector<string> FileManager::ReadStats() {

    vector<string> data;
    vector<vector<string>> dataList;
    string line = "";

    ifstream file("pokemonData.txt");

    string num;
    string name;
    string type1;
    string type2;
    string total;
    string hp;
    string atk;
    string def;
    string spAtk;
    string spDef;
    string spd;
    string gen;
    string legendary;

    bool pokemonFound = false;
    while(!pokemonFound) {

        getline(file, num, ',');
        getline(file, name, ',');
        getline(file, type1, ',');
        getline(file, type2, ',');
        getline(file, total, ',');
        getline(file, hp, ',');
        getline(file, atk, ',');
        getline(file, def, ',');
        getline(file, spAtk, ',');
        getline(file, spDef, ',');
        getline(file, spd, ',');
        getline(file, gen, ',');
        getline(file, legendary, '\n');

    if (name == name_) {

        /*cout << "Name entered as input: " << name_ << endl;
        cout << "Num from file: " << num << endl;
        cout << "Name from file: " << name << endl;*/
        pokemonFound = true;
        data.push_back(type1);
        data.push_back(type2);
        data.push_back(hp);
        data.push_back(atk);
        data.push_back(def);
        data.push_back(spAtk);
        data.push_back(spDef);
        data.push_back(spd);

    }
    
    
    }

    return data;
}