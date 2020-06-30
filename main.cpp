#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    Pokemon p;

    p.setName("Torchic");
    p.setType("Fire");

    Move ember("Ember", "Fire");
    Move fireBlast("Fire Blast", "Fire");
    Move fireSpin("Fire Spin", "Fire");
    Move flameWheel("Flame Wheel", "Fire");
    Move flamethrower("FlameThrower", "Fire");
    p.AddMove(ember);
    p.AddMove(fireBlast);
    p.AddMove(flameWheel);
    p.AddMove(fireSpin);
    //p.AddMove(flamethrower);
    //p.ViewMoves();

    Pokemon p2;

    p2.setName("Treeko");
    p2.setType("Grass");

    Pokemon p3;

    p3.setName("Bulbasaur");
    p3.setType("Grass");

    Pokemon p4;

    p4.setName("Charmander");
    p4.setType("Fire");

    Pokemon p5;

    p5.setName("Pidgey");
    p5.setType("Flying");

    Pokemon p6;

    p6.setName("Pikachu");
    p6.setType("Electric");

    Pokemon p7;

    p7.setName("Onix");
    p7.setType("Rock");


    Team team;

    team.AddPokemon(p);
    team.AddPokemon(p2);
    team.AddPokemon(p3);
    team.AddPokemon(p4);
    team.AddPokemon(p5);
    team.AddPokemon(p6);

    //team.ViewTeam();

    team.AddPokemon(p7);
    string name;
    cout << "What is your name?" << endl;
    cin >> name;

    Trainer user(team, name);

    GameManager game(user);
    game.GenerateTrainer();

    bool keepGoing = true;

    while(keepGoing) {

        cout << "Would you like to battle a trainer or find wild pokemon? (1, 2)" << endl;

        int input;
        cin >> input;

        if (input == 1) {

            game.BattleTrainer();

        } else if (input == 2) {

            game.EncounterPokemon();

        } else {

            keepGoing = false;

        }
    }


}
