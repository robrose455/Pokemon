#include <string>
#include <iostream>
#include <vector>
#include "Move.h"


using namespace std;

class Pokemon
{
    public:

        Pokemon();
        Pokemon(string name, string type);

        void AddMove(Move m);
        void ViewMoves();

        void setName(string name);
        string getName();

        void setType(string type);
        string getType();

        void setMaxHp(int hp);
        int getMaxHp();

        void setCurHp(int hp);
        int getCurHp();

    private:

        string name_;
        string type_;

        int maxHp_;
        int curHp_;

        vector<Move> moves_;



};

