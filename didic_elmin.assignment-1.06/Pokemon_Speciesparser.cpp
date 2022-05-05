//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;



class pokemon_species_t {
public:
    pokemon_species_t()
    {

    }
    pokemon_species_t(
            int id,
            string identifier,
            int generation_id,
            int evolves_from_species_id,
            int evolution_chain_id,
            int color_id,
            int shape_id,
            int habitat_id,
            int gender_rate,
            int capture_rate,
            int base_happiness,
            int is_baby,
            int hatch_counter,
            int has_gender_differences,
            int growth_rate_id,
            int forms_switchable,
            int is_legendary,
            int is_mythical,
            int order,
            int conquest_order
    ) {
            
                this->id = id;                      
                this->identifier = identifier;
                this->generation_id = generation_id;
                this->evolves_from_species_id = evolves_from_species_id;
                this->evolution_chain_id = evolution_chain_id;
                this->color_id = color_id;
                this->shape_id = shape_id;
                this->habitat_id = habitat_id;
                this->gender_rate = gender_rate;
                this->capture_rate = capture_rate;
                this->base_happiness = base_happiness;
                this->is_baby = is_baby;
                this->hatch_counter = hatch_counter;
                this->has_gender_differences = has_gender_differences;
                this->growth_rate_id = growth_rate_id;
                this->forms_switchable = forms_switchable;
                this->is_legendary = is_legendary;
                this->is_mythical = is_mythical;
                this->order = order;
                this->conquest_order = conquest_order;

    }

    void display() {
        cout << " pokemon_species id: " << id << endl;
        cout << " pokemon_species identifier: " << identifier << endl;
        cout << " pokemon_species evolves_from_species_id: " << evolves_from_species_id << endl;
        cout << " pokemon_species evolution_chain_id: " << evolution_chain_id << endl;
        cout << " pokemon_species color_id: " << color_id << endl;
        cout << " pokemon_species shape_id: " << shape_id << endl;
        cout << " pokemon_species habitat_id: " << habitat_id << endl;
        cout << " pokemon_species gender_rate: " << gender_rate << endl;
        cout << " pokemon_species capture_rate: " << capture_rate << endl;
        cout << " pokemon_species base_happiness: " << base_happiness << endl;
        cout << " pokemon_species is_baby: " << is_baby << endl;
        cout << " pokemon_species hatch_counter: " << hatch_counter << endl;
        cout << " pokemon_species has_gender_differences: " << has_gender_differences << endl;
        cout << " pokemon_species growth_rate_id: " << growth_rate_id << endl;
        cout << " pokemon_species forms_switchable: " << forms_switchable << endl;
        cout << " pokemon_species is_legendary: " << is_legendary << endl;
        cout << " pokemon_species is_mythical: " << is_mythical << endl;
        cout << " pokemon_species order: " << order << endl;
        cout << " pokemon_species conquest_order: " << conquest_order << endl;
    

        

    }

            int id;
            string identifier;
            int generation_id;
            int evolves_from_species_id;
            int evolution_chain_id;
            int color_id;
            int shape_id;
            int habitat_id;
            int gender_rate;
            int capture_rate;
            int base_happiness;
            int is_baby;
            int hatch_counter;
            int has_gender_differences;
            int growth_rate_id;
            int forms_switchable;
            int is_legendary;
            int is_mythical;
            int order;
            int conquest_order;
};

void displaySpecies(vector<pokemon_species_t>& pokemons_species)
{

        for(int i = 0; i < pokemons_species.size(); i++)
        {
            pokemons_species[i].display();
        }
    
}

int pokemon_species()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/pokemon_species.csv");
    string line;


    vector<pokemon_species_t> pokemons_species;
    
  
    int id;
    string identifier;
    int generation_id;
    int evolves_from_species_id;
    int evolution_chain_id;
    int color_id;
    int shape_id;
    int habitat_id;
    int gender_rate;
    int capture_rate;
    int base_happiness;
    int is_baby;
    int hatch_counter;
    int has_gender_differences;
    int growth_rate_id;
    int forms_switchable;
    int is_legendary;
    int is_mythical;
    int order;
    int conquest_order;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        
        getline(inputString, identifier, ',');

        getline(inputString, tempString, ',');
        generation_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        evolves_from_species_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        evolution_chain_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        color_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        shape_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        habitat_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        gender_rate = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        capture_rate = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        base_happiness = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        is_baby = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        hatch_counter = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        has_gender_differences = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        growth_rate_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        forms_switchable = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        is_legendary = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        is_mythical = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        order = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        conquest_order = atoi(tempString.c_str());


        pokemon_species_t pokemon_specie(
            id,
            identifier,
            generation_id,
            evolves_from_species_id,
            evolution_chain_id,
            color_id,
            shape_id,
            habitat_id,
            gender_rate,
            capture_rate,
            base_happiness,
            is_baby,
            hatch_counter,
            has_gender_differences,
            growth_rate_id,
            forms_switchable,
            is_legendary,
            is_mythical,
            order,
            conquest_order
        );

        pokemons_species.push_back(pokemon_specie);
        line = "";
    }


    displaySpecies(pokemons_species);

    return 0;
}


