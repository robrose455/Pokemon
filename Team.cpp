#include "Team.h"
#include <string>
#include <iostream>

using namespace std;

Team::Team() {



}

void Team::AddPokemon(Pokemon p) {


    if (pokeVect_.size() < 6) {

        pokeVect_.push_back(p);
        string name;
        name = p.getName();
        // cout << "POKEMON ADDED: " << name << endl;

    } else {

        // cout << "CANNOT ADD POKEMON -- TEAM FULL" << endl;
    }

    return;
}

void Team::ViewTeam() {

    string name;

    for (int i = 0; i < pokeVect_.size(); i++) {

        name = pokeVect_[i].getName();
        cout << name << " || " ;


    }

    cout << endl;
}

