#include "Trainer.h"

class BattleManager
{
    public:

        BattleManager();
        BattleManager(Trainer user, Trainer enemy);

        void InitiateBattle();



    private:

        Trainer user_;
        Trainer enemy_;
        Pokemon userActivePokemon_;
        Pokemon enemyActivePokemon_;

};

