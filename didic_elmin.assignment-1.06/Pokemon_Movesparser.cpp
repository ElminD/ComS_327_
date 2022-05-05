//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// pokemon_id,
// version_group_id,
// move_id,
// pokemon_move_method_id,
// level,
// order

class pokemon_moves_t {
public:
    pokemon_moves_t()
    {

    }
    pokemon_moves_t(
            int pokemon_id,
            int version_group_id,
            int move_id,
            int pokemon_move_method_id,
            int level,
            int order
    ) {
            this->pokemon_id = pokemon_id;
            this->version_group_id = version_group_id;
            this->move_id = move_id;
            this->pokemon_move_method_id = pokemon_move_method_id;
            this->level = level;
            this->order = order;

    }

    void display() {
        cout << " pokemon_moves pokemon_id: " << pokemon_id << endl;
        cout << " pokemon_moves version_group_id: " << version_group_id << endl;
        cout << " pokemon_moves move_id: " << move_id << endl;
        cout << " pokemon_moves pokemon_move_method_id: " << pokemon_move_method_id << endl;
        cout << " pokemon_moves level: " << level << endl;
        cout << " pokemon_moves order " << order << endl;
        

    }

     int pokemon_id;
     int version_group_id;
     int move_id;
     int pokemon_move_method_id;
     int level;
     int order;
};

void displayPokemonMoves(vector<pokemon_moves_t>& pokemons_moves)
{

        for(int i = 0; i < pokemons_moves.size(); i++)
        {
            pokemons_moves[i].display();
        }
    
}

int pokemon_moves()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/pokemon_moves.csv");
    string line;


    vector<pokemon_moves_t> pokemons_moves;
   

    int pokemon_id;
    int version_group_id;
    int move_id;
    int pokemon_move_method_id;
    int level;
    int order;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        pokemon_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        version_group_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        move_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        pokemon_move_method_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        level = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        order = atoi(tempString.c_str());

        pokemon_moves_t pokemon_move(
            pokemon_id,
            version_group_id,
            move_id,
            pokemon_move_method_id,
            level,
            order

        );

        pokemons_moves.push_back(pokemon_move);
        line = "";
    }


    displayPokemonMoves(pokemons_moves);

    return 0;
}


