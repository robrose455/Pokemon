#include <vector>
#include "Pokemon.h"
using namespace std;

class Team
{
    public:


        Team();

        void AddPokemon(Pokemon p);
        void ViewTeam();

    private:

        vector<Pokemon> pokeVect_;


};

