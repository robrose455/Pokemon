#include "Trainer.h"

Trainer::Trainer() {

}

Trainer::Trainer(Team pokeTeam, string name)
: pokeTeam_(pokeTeam), name_(name) {}

void Trainer::ViewTeam() {

    cout << "TRAINER: " << name_ << endl;
    pokeTeam_.ViewTeam();
    cout << endl;

}

string Trainer::getName() {

    return name_;

}

