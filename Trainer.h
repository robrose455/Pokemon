#ifndef TRAINER_H
#define TRAINER_H
#include "Team.h"

class Trainer
{
    public:

        Trainer();
        Trainer(Team pokeTeam, string name);
        void ViewTeam();
        string getName();



    private:

        string name_;
        Team pokeTeam_;

};

#endif // TRAINER_H
