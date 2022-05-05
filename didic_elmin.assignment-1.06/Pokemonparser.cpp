//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class pokemon_t {
public:
    pokemon_t()
    {

    }
    pokemon_t(
            int pokemonId,
            string pokemonName,
            int species_id,
            int height,
            int weight,
            int base_experience,
            int order,
            int is_default
    ) {
        this->pokemonId = pokemonId;
        this->pokemonName = pokemonName;
        this->species_id = species_id;
        this->height = height;
        this->weight = weight;
        this->base_experience = base_experience;
        this->order = order;
        this->is_default = is_default;

    }

    void display() {
        cout << " Pokemon ID: " << pokemonId << endl;
        cout << " Pokemon Name: " << pokemonName << endl;
        cout << " Pokemon Species ID: " << species_id << endl;
        cout << " Pokemon height: " << height << endl;
        cout << " Pokemon weight: " << weight << endl;
        cout << " Pokemon base_experience: " << base_experience << endl;
        cout << " Pokemon order: " << order << endl;
        cout << " Pokemon is_default: " << is_default << endl;

    }

    int pokemonId;
    string pokemonName;
    int species_id;
    int height;
    int weight;
    int base_experience;
    int order;
    int is_default;
};

void displayPokemon(vector<pokemon_t>& pokemons)
{

        for(int i = 0; i < pokemons.size(); i++)
        {
            pokemons[i].display();
        }
    
}

int pokemon()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/pokemon.csv");
    string line;


    vector<pokemon_t> pokemons;
   

    int pokemonId;
    string pokemonName;
    int species_id,height,weight,base_experience,order,is_default;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        pokemonId = atoi(tempString.c_str());
        

        getline(inputString, pokemonName, ',');

        getline(inputString, tempString, ',');
        species_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        height = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        weight = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        base_experience = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        order = atoi(tempString.c_str());
       

        getline(inputString, tempString, ',');
        is_default = atoi(tempString.c_str());
        



        pokemon_t pokemon(
                pokemonId,
                pokemonName,
                species_id,
                height,
                weight,
                base_experience,
                order,
                is_default
        );

        pokemons.push_back(pokemon);
        line = "";
    }


    displayPokemon(pokemons);

    return 0;
}


