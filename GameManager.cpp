#include "GameManager.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

GameManager::GameManager(Trainer user)
: user_(user)
{
    PopulatePokemonPool();
}

void GameManager::PopulatePokemonPool() {

    string names[10] = {"Togepi", "Squirtle", "Eevee", "Pikachu", "Charmander", "Bulbasaur", "Onix", "Mankey", "Pidgey", "Kyogre"};
    string types[10] = {"Normal", "Water", "Normal", "Electric", "Fire", "Grass", "Rock", "Fighting", "Water"};

    for (int i = 0; i < 10; i++) {

        Pokemon p(names[i], types[i]);
        pokePool_.push_back(p);

    }
}

Trainer GameManager::GenerateTrainer() {


    srand((unsigned) time(0));
    int index;


    Team enemyTeam;

    for (int i = 0; i < 6; i++) {

        index = (rand() % 10);
        enemyTeam.AddPokemon(pokePool_[index]);

    }

    // enemyTeam.ViewTeam();
    Trainer enemy(enemyTeam, "Joe Mama");
    return enemy;

}

void GameManager::BattleTrainer() {

    Trainer enemy;
    enemy = GenerateTrainer();

    enemy.ViewTeam();
    user_.ViewTeam();

    cout << "You battle and you win, good job sport." << endl;



}

void GameManager::EncounterPokemon() {

    srand((unsigned) time(0));
    int index;
    index = (rand() % 10);

    Team wildTeam;
    wildTeam.AddPokemon(pokePool_[index]);

    Trainer wildPokemon(wildTeam, pokePool_[index].getName());

    wildPokemon.ViewTeam();
    user_.ViewTeam();

    cout << "You beat the shit out of the wild pokemon." << endl;

}
