#include "Pokemon.h"
#include "Pokemon.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Pokemon::Pokemon()
{

}

Pokemon::Pokemon(string name, int lvl)
    : name_(name), lvl_(lvl) {

    FileManager fm("pokemonData.txt", name_);
    vector<string> statsData = fm.ReadStats();

    type1_ = statsData[0];
    type2_ = statsData[1];
    baseHp_ = stoi(statsData[2]);
    baseAtk_ = stoi(statsData[3]);
    baseDef_ = stoi(statsData[4]);
    baseSpatk_ = stoi(statsData[5]);
    baseSpdef_ = stoi(statsData[6]);
    baseSpd_ = stoi(statsData[7]);
    XPGroup_ = "Slow";

    SetExperience();
    SetNature();
    CreateIVs();
    UpdateCurrentStats();

    cout << "POKEMON CREATED: ---- " << name_ << endl;
    cout << "CURRENT LEVEL: " << lvl_ << endl;
    cout << "NATURE: " << nature_ << endl;
    cout << "TYPE: " << type1_ << " / " << type2_ << endl;
    cout << "BASE HP: " << baseHp_ << endl;
    cout << "BASE ATK: " << baseAtk_ << endl;
    cout << "BASE DEF: " << baseDef_ << endl;
    cout << "BASE SPATK: " << baseSpatk_ << endl;
    cout << "BASE SPDEF: " << baseSpdef_ << endl;
    cout << "BASE SPEED: " << baseSpd_ << endl;
    cout << "\n" << endl;

    cout << "IVs" << endl;
    cout << "ATK IV: " << AtkIV_ << endl;
    cout << "DEF IV: " << DefIV_ << endl;
    cout << "SPATK IV: " << SpAtkIV_ << endl;
    cout << "SPDEF IV: " << SpDefIV_ << endl;
    cout << "SPEED IV: " << SpdIV_ << endl;
    cout << "\n" << endl;

    cout << "CURRENT STATS" << endl;
    cout << "MAX HP: " << maxHp_ << endl;
    cout << "ATTACK: " << atk_ << endl;
    cout << "DEFENSE: " << def_ << endl;
    cout << "SPECIAL ATTACK: " << spAtk_ << endl;
    cout << "SPECIAL DEFENSE: " << spDef_ << endl;
    cout << "SPEED: " << spd_ << endl;
    cout << "\n" << endl;

}

void Pokemon::SetExperience() {


    if (XPGroup_ == "Erratic") {

        int nextLvl = lvl_ + 1;

        if (lvl_ <= 50) {

            totalXP_ = (((lvl_ * lvl_ * lvl_) * (100 - lvl_)) / 50);
            XPUntilNextLvl = (((nextLvl * nextLvl * nextLvl) * (100 - nextLvl)) / 50);

        }
        else if (lvl_ > 50 && lvl_ < 68) {

            totalXP_ = (((lvl_ * lvl_ * lvl_) * (100 - lvl_)) / 100);
            XPUntilNextLvl = (((nextLvl * nextLvl * nextLvl) * (100 - nextLvl)) / 100);

        }
        else if (lvl_ >= 68 && lvl_ > 98) {

            totalXP_ = (((lvl_ * lvl_ * lvl_) * ((1911 - 10 * lvl_)/3) / 500));
            XPUntilNextLvl = (((nextLvl * nextLvl * nextLvl) * ((1911 - 10 * nextLvl)/3) / 500));

        }
        else if (lvl_ >= 98) {

            totalXP_ = (((lvl_ * lvl_ * lvl_) * (160 - lvl_)) / 100);
            XPUntilNextLvl = (((nextLvl * nextLvl * nextLvl) * (160 - nextLvl)) / 100);

        }

        cout << totalXP_ << " <--- Total XP" << endl;
        cout << XPUntilNextLvl << " <--- XP Next Lvel" << endl;


    }

    if (XPGroup_ == "Fast") {


        totalXP_ = ((4 * (lvl_ * lvl_ * lvl_)) / 5);

        int nextLvl = lvl_ + 1;
        XPUntilNextLvl = ((4 * (nextLvl * nextLvl * nextLvl)) / 5);

        //cout << totalXP_ << " <--- Total XP" << endl;
        //cout << XPUntilNextLvl << " <--- XP Next Lvel" << endl;
    }

    if (XPGroup_ == "Medium Fast") {

        int nextLvl = lvl_ + 1;

        totalXP_ = (lvl_ * lvl_ * lvl_);
        XPUntilNextLvl = (nextLvl * nextLvl * nextLvl);

        //cout << totalXP_ << " <--- Total XP" << endl;
        //cout << XPUntilNextLvl << " <--- XP Next Lvel" << endl;

    } 
    
    if (XPGroup_ == "Medium Slow") {

        int nextLvl = lvl_ + 1;
        totalXP_ = (6 * (lvl_ * lvl_ * lvl_) / 5) - (15 * (lvl_ * lvl_)) + (100 * lvl_) - 140;
        XPUntilNextLvl = (6 * (nextLvl * nextLvl * nextLvl) / 5) - (15 * (nextLvl * nextLvl)) + (100 * nextLvl) - 140;

        cout << totalXP_ << " <--- Total XP" << endl;
        cout << XPUntilNextLvl << " <--- XP Next Lvel" << endl;

    } 

    if (XPGroup_ == "Slow") {

        int nextLvl = lvl_ + 1;
        totalXP_ = (5 * (lvl_ * lvl_ * lvl_) / 4);
        XPUntilNextLvl = ( 5 * (nextLvl * nextLvl * nextLvl) / 4);

        cout << totalXP_ << " <--- Total XP" << endl;
        cout << XPUntilNextLvl << " <--- XP Next Lvel" << endl;

    }


    if (XPGroup_ == "Fluctuating") {

        int nextLvl = lvl_ + 1;


    }





}

void Pokemon::CreateIVs() {

    vector<int> IVs;
    srand((unsigned)time(0));
    int num;

    for (int i = 0; i < 6; i++) {

        num = (rand() % 31) + 1;
        IVs.push_back(num);
        cout << "IV : " << num <<  endl;

    }

    HpIV_ = IVs[0];
    AtkIV_ = IVs[1];
    DefIV_ = IVs[2];
    SpAtkIV_ = IVs[3];
    SpDefIV_ = IVs[4];
    SpdIV_ = IVs[5];

    return;

}

void Pokemon::UpdateCurrentStats() {

    maxHp_ = (((2 * baseHp_ + HpIV_) * lvl_) / 100 ) + lvl_ + 10;
    curHp_ = maxHp_;

    atk_ = (((2 * baseAtk_ + AtkIV_) * lvl_) / 100) + 5;
    def_ = (((2 * baseDef_ + DefIV_) * lvl_) / 100) + 5;
    spAtk_ = (((2 * baseSpatk_ + SpAtkIV_) * lvl_) / 100) + 5;
    spDef_ = (((2 * baseSpdef_ + SpDefIV_) * lvl_) / 100) + 5;
    spd_ = (((2 * baseSpd_ + SpdIV_) * lvl_) / 100) + 5;

    if (nature_ == "Adamant") {

        atk_ = atk_ * 1.1;
        spAtk_ = spAtk_ * 0.9;

    }
    else if (nature_ == "Bashful") {

        //Neutral

    }
    else if (nature_ == "Bold") {

        def_ = def_ * 1.1;
        atk_ = atk_ * 0.9;

    }
    else if (nature_ == "Brave") {

        atk_ = atk_ * 1.1;
        spd_ = spd_ * 0.9;
    }
    else if (nature_ == "Calm") {

        spDef_ = spDef_ * 1.1;
        atk_ = atk_ * 0.9;
    }
    else if (nature_ == "Careful") {

        spDef_ = spDef_ * 1.1;
        spAtk_ = spAtk_ * 0.9;

    }
    else if (nature_ == "Docile") {

        //Neutral

    }
    else if (nature_ == "Gentle") {

        spDef_ = spDef_ * 1.1;
        def_ = def_ * 0.9;

    }
    else if (nature_ == "Hardy") {

        //Neutral

    }
    else if (nature_ == "Hasty") {

        spd_ = spd_ * 1.1;
        def_ = def_ * 0.9;

    }

    else if (nature_ == "Impish") {

        def_ = def_ * 1.1;
        spAtk_ = spAtk_ * 0.9;

    }

    else if (nature_ == "Jolly") {

        spd_ = spd_ * 1.1;
        spAtk_ = spAtk_ * 0.9;

    }

    else if (nature_ == "Lax") {

        def_ = def_ * 1.1;
        spDef_ = spDef_ * 0.9;

    }

    else if (nature_ == "Lonely") {

        atk_ = atk_ * 1.1;
        def_ = def_ * 0.9;

    }

    else if (nature_ == "Mild") {

        spAtk_ = spAtk_ * 1.1;
        def_ = def_ * 0.9;

    }

    else if (nature_ == "Modest") {

        spAtk_ = spAtk_ * 1.1;
        atk_ = atk_ * 0.9;

    }

    else if (nature_ == "Naive") {

        spd_ = spd_ * 1.1;
        spDef_ = spDef_ * 0.9;

    }

    else if (nature_ == "Naughty") {

        atk_ = atk_ * 1.1;
        spDef_ = spDef_ * 0.9;

    }

    else if (nature_ == "Quiet") {

        spAtk_ = spAtk_ * 1.1;
        spd_ = spd_ * 0.9;

    }

    else if (nature_ == "Quirky") {

        spDef_ = spDef_ * 1.1;
        spDef_ = spDef_ * 0.9;

    }

    else if (nature_ == "Rash") {

        spAtk_ = spAtk_ * 1.1;
        spDef_ = spDef_ * 0.9;

    }

    else if (nature_ == "Relaxed") {

        def_ = def_ * 1.1;
        spd_ = spd_ * 0.9;

    }

    else if (nature_ == "Sassy") {

        spDef_ = spDef_ * 1.1;
        spd_ = spd_ * 0.9;
    
    }

    else if (nature_ == "Timid") {

        spd_ = spd_ * 1.1;
        atk_ = atk_ * 0.9;
    }

    return;

}

void Pokemon::SetNature() {

    
    string natures[25] = { "Adamant", "Bashful", "Bold", "Brave", "Calm", "Careful", "Docile", "Gentle", "Hardy", "Hasty", "Impish", "Jolly", "Lax", "Lonely", "Mild", "Modest", "Naive", "Naughty", "Quiet", "Quirky", "Rash", "Relaxed", "Sassy", "Serious", "Timid" };
    srand((unsigned)time(0));
    int num;
    num = (rand() % 25);

    nature_ = natures[num];
    

};

void Pokemon::GainExperience(int xpGain) {

    cout << name_ << " gained " << xpGain << " points of XP!" << endl;
    int prevXp = totalXP_;
    totalXP_ = totalXP_ + xpGain;

    while (totalXP_ >= XPUntilNextLvl) {

        LvlUp();
        int extraXP = totalXP_ - XPUntilNextLvl;
        SetExperience();
        totalXP_ = totalXP_ + extraXP;

    }
    
    
    

}

void Pokemon::LvlUp() {

    lvl_++;

    //Check if can evolve
    int oldHp = maxHp_;
    int oldAtk = atk_;
    int oldDef = def_;
    int oldSpAtk = spAtk_;
    int oldSpDef = spDef_;
    int oldSpd = spd_;

    UpdateCurrentStats();

    cout << name_ << " leveled up to level " << lvl_ << "!" << endl;
    cout << "HP : " << oldHp << " ----> " << maxHp_ << endl;
    cout << "ATK : " << oldAtk << " ----> " << atk_ << endl;
    cout << "DEF : " << oldDef << " ----> " << def_ << endl;
    cout << "SPATK : " << oldSpAtk << " ----> " << spAtk_ << endl;
    cout << "SPDEF : " << oldSpDef << " ----> " << spDef_ << endl;
    cout << "SPD : " << oldSpd << " ----> " << spd_ << endl;
    cout << "\n" << endl;

    
    

}

void Pokemon::AddMove(Move m) {

    if (moves_.size() < 4) {

        moves_.push_back(m);

    }
    else if (moves_.size() == 4) {

        cout << "Would you like to delete a move for " << m.getName() << "? (Y/N)" << endl;
        char input;
        cin >> input;

        if (input == 'Y') {

            Pokemon::ViewMoves();
            cout << "What move should be deleted? (1, 2, 3, 4)" << endl;

            char input2;
            cin >> input2;

            if (input2 == '1') {

                moves_.erase(moves_.begin());
                moves_.push_back(m);

            }
            else if (input2 == '2') {

                moves_.erase(moves_.begin() + 1);
                moves_.push_back(m);

            }
            else if (input2 == '3') {

                moves_.erase(moves_.begin() + 2);
                moves_.push_back(m);

            }
            else if (input2 == '4') {

                moves_.erase(moves_.begin() + 3);
                moves_.push_back(m);

            }

        }
    }
    return;

}

void Pokemon::ViewMoves() {

    for (int i = 0; i < moves_.size(); i++) {

        string moveName;
        moveName = moves_[i].getName();

        cout << moveName << " || ";

    }

    cout << endl;

}

void Pokemon::setName(string name) {

    name_ = name;


}

string Pokemon::getName() {

    return name_;

}

void Pokemon::setNature(string nature) {

    nature_ = nature;


}

string Pokemon::getNature() {

    return nature_;

}

void Pokemon::setType1(string type1) {

    type1_ = type1;


}

string Pokemon::getType1() {

    return type1_;

}

void Pokemon::setType2(string type2) {

    type1_ = type2;


}

string Pokemon::getType2() {

    return type2_;

}

void Pokemon::setLvl(int lvl) {

    lvl_ = lvl;

}

int Pokemon::getLvl() {

    return lvl_;

}

void Pokemon::setBaseHp(int baseHp) {

    baseHp_ = baseHp;

}

int Pokemon::getBaseHp() {

    return baseHp_;

}

void Pokemon::setBaseAtk(int baseAtk) {

    baseAtk_ = baseAtk;

}

int Pokemon::getBaseAtk() {

    return baseAtk_;

}

void Pokemon::setBaseDef(int baseDef) {

    baseDef_ = baseDef;

}

int Pokemon::getBaseDef() {

    return baseDef_;

}

void Pokemon::setBaseSpd(int baseSpd) {

    baseSpd_ = baseSpd;

}

int Pokemon::getBaseSpd() {

    return baseSpd_;

}

void Pokemon::setBaseSpatk(int baseSpatk) {

    baseSpatk_ = baseSpatk;

}

int Pokemon::getBaseSpatk() {

    return baseSpatk_;

}

void Pokemon::setBaseSpdef(int baseSpdef) {

    baseSpdef_ = baseSpdef;

}

int Pokemon::getBaseSpdef() {

    return baseSpdef_;

}

void Pokemon::setAtk(int atk) {

    atk_ = atk;

}

int Pokemon::getAtk() {

    return atk_;

}

void Pokemon::setDef(int def) {

    def_ = def;

}

int Pokemon::getDef() {

    return def_;

}

void Pokemon::setSpAtk(int spAtk) {

    spAtk_ = spAtk;

}

int Pokemon::getSpAtk() {

    return spAtk_;

}

void Pokemon::setSpDef(int spDef) {

    spDef_ = spDef;

}

int Pokemon::getSpDef() {

    return spDef_;

}

void Pokemon::setSpd(int spd) {

    spd_ = spd;

}

int Pokemon::getSpd() {

    return spd_;

}

