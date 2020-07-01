#include "BattleManager.h"
#include <cstdlib>
#include <ctime>

BattleManager::BattleManager()
{

}

BattleManager::BattleManager(Trainer user, Trainer enemy)
: user_(user), enemy_(enemy) {}

void BattleManager::InitiateBattle() {

    userActivePokemon_ = user_.pokeTeam_.pokeVect_[0];
    enemyActivePokemon_ = enemy_.pokeTeam_.pokeVect_[0];

    string name = userActivePokemon_.getName();
    string name2 = enemyActivePokemon_.getName();

    cout << name << endl;
    cout << name2 << endl;

    userActivePokemon_.ViewMoves();
    cout << "Choose a move to fight: (1, 2, 3, 4)" << endl;
    int input;
    cin >> input;

    if (input == 1) {

        string moveName = userActivePokemon_.moves_[0].getName();
        cout << name << " used " << moveName << "!" << endl;

    } else if (input == 2) {

        string moveName = userActivePokemon_.moves_[1].getName();
        cout << name << " used " << moveName << "!" << endl;

    } else if (input == 3) {

        string moveName = userActivePokemon_.moves_[2].getName();
        cout << name << " used " << moveName << "!" << endl;

    } else if (input == 4) {

        string moveName = userActivePokemon_.moves_[3].getName();
        cout << name << " used " << moveName << "!" << endl;

    }

    srand((unsigned) time(0));
    int enemyMoveIndex;
    enemyMoveIndex = (rand() % 4);

    if (enemyMoveIndex == 1) {

        string moveName = enemyActivePokemon_.moves_[0].getName();
        cout << name2 << " used " << moveName << "!" << endl;

    } else if (enemyMoveIndex == 2) {

        string moveName = enemyActivePokemon_.moves_[1].getName();
        cout << name2 << " used " << moveName << "!" << endl;

    } else if (enemyMoveIndex == 3) {

        string moveName = enemyActivePokemon_.moves_[2].getName();
        cout << name2 << " used " << moveName << "!" << endl;

    } else if (enemyMoveIndex == 4) {

        string moveName = enemyActivePokemon_.moves_[3].getName();
        cout << name2 << " used " << moveName << "!" << endl;

    }


}
