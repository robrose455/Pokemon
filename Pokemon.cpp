#include "Pokemon.h"
#include <vector>

Pokemon::Pokemon()
{

}

Pokemon::Pokemon(string name, string type)
: name_(name), type_(type) {}

void Pokemon::AddMove(Move m) {

    if (moves_.size() < 4) {

        moves_.push_back(m);

    } else if (moves_.size() == 4) {

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

            } else if (input2 == '2') {

                moves_.erase(moves_.begin() + 1);
                moves_.push_back(m);

            } else if (input2 == '3') {

                moves_.erase(moves_.begin() + 2);
                moves_.push_back(m);

            } else if (input2 == '4') {

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

        cout << moveName << " || " ;

    }

    cout << endl;

}

void Pokemon::setName(string name) {

    name_ = name;


}

string Pokemon::getName() {

    return name_;

}

void Pokemon::setType(string type) {

    type_ = type;


}

string Pokemon::getType() {

    return type_;

}






