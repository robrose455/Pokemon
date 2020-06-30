#include <string>
#include <iostream>

using namespace std;


class Move
{
    public:

        Move();
        Move(string name, string type);

        void setName(string name);
        string getName();

        void setType(string type);
        string getType();


    private:

        string name_;
        string type_;

};


