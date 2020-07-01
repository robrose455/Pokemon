#include "Trainer.h"
#include "BattleManager.h"

class GameManager
{
    public:

        GameManager(Trainer user);
        void PopulatePokemonPool();

        Trainer GenerateTrainer();
        void BattleTrainer();
        void EncounterPokemon();






    private:

        Trainer user_;
        vector<Pokemon> pokePool_;

};


