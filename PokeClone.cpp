#include <iostream>
#include "GameManager.h"
#include <fstream>

using namespace std;

int main()
{


    // TEST FILE READING


    Pokemon p("Alakazam", 100);

    /*p.setName("Torchic");
    p.setType1("Fire");

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
    //p.ViewMoves(); */



    Team team;

    
    string name;
    cout << "What is your name?" << endl;
    cin >> name;

    Trainer user(team, name);

    GameManager game(user);
    game.GenerateTrainer();

    bool keepGoing = true;

    while (keepGoing) {

        cout << "Would you like to battle a trainer or find wild pokemon? (1, 2)" << endl;

        int input;
        cin >> input;

        if (input == 1) {

            game.BattleTrainer();

        }
        else if (input == 2) {

            game.EncounterPokemon();

        }
        else {

            keepGoing = false;

        }
    }


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
