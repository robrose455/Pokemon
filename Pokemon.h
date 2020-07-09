#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Move.h"
#include "FileManager.h"

using namespace std;

class Pokemon
{
public:

    Pokemon();
    Pokemon(string name, int lvl);

    void AddMove(Move m);
    void ViewMoves();

    void SetExperience();
    void UpdateCurrentStats();
    void CreateIVs(); 
    void SetNature();

    void GainExperience(int xpGain);
    void LvlUp();

    void setName(string name);
    string getName();

    void setType1(string type1);
    string getType1();

    void setType2(string type2);
    string getType2();

    void setNature(string nature);
    string getNature();

    void setLvl(int lvl);
    int getLvl();

    void setAtk(int atk);
    int getAtk();

    void setDef(int def);
    int getDef();

    void setSpd(int spd);
    int getSpd();

    void setSpAtk(int SpAtk);
    int getSpAtk();

    void setSpDef(int SpDef);
    int getSpDef();

    void setBaseHp(int baseHp);
    int getBaseHp();

    void setBaseAtk(int baseAtk);
    int getBaseAtk();

    void setBaseDef(int baseDef);
    int getBaseDef();

    void setBaseSpd(int baseSpd);
    int getBaseSpd();

    void setBaseSpatk(int baseSpatk);
    int getBaseSpatk();

    void setBaseSpdef(int baseSpdef);
    int getBaseSpdef();

    void setMaxHp(int hp);
    int getMaxHp();

    void setCurHp(int hp);
    int getCurHp();

    vector<Move> moves_;

private:

    string name_;
    string type1_;
    string type2_;
    string nature_; 

    int lvl_ = 0;
    int maxHp_ = 0;
    int curHp_ = 0;
    int atk_ = 0;
    int def_ = 0;
    int spAtk_ = 0;
    int spDef_ = 0;
    int spd_ = 0;

    int HpIV_ = 0;
    int AtkIV_ = 0;
    int DefIV_ = 0;
    int SpAtkIV_ = 0;
    int SpDefIV_ = 0;
    int SpdIV_ = 0;


    int baseHp_ = 0;
    int baseAtk_ = 0;
    int baseDef_ = 0;
    int baseSpd_ = 0;
    int baseSpatk_ = 0;
    int baseSpdef_ = 0;

    int totalXP_ = 0;
    int XPUntilNextLvl = 0;
    string XPGroup_;

};


