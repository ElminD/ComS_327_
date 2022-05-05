#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


#include "heap.h"
#include "poke327.h"
#include "character.h"
#include "io.h"

typedef struct queue_node {
  int x, y;
  struct queue_node *next;
} queue_node_t;

world_t world;

pair_t all_dirs[8] = {
  { -1, -1 },
  { -1,  0 },
  { -1,  1 },
  {  0, -1 },
  {  0,  1 },
  {  1, -1 },
  {  1,  0 },
  {  1,  1 },
};

class type_names_t {
public:
    type_names_t()
    {

    }
    type_names_t(
            int type_id,
            int local_language_id,
            string name
    ) {
       
        this->type_id = type_id;
        this->local_language_id = local_language_id;
        this->name = name;

    }

    void display() {
        
        cout << " type_names type_id: " << type_id << endl;
        cout << " type_names local_language_id: " << local_language_id << endl;
        cout << " type_names name: " << name << endl;

    }

    
    int type_id;
    int local_language_id;
    string name;
};

void displayTypeNames(vector<type_names_t>& Pokenames)
{

        for(int i = 0; i < Pokenames.size(); i++)
        {
            Pokenames[i].display();
        }
    
}

int type_names()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/type_names.csv");
    string line;


    vector<type_names_t> Pokenames;
   

    
    int type_id;
    int local_language_id;
    string name;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        type_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        local_language_id = atoi(tempString.c_str());
        
        getline(inputString, name, ',');

        type_names_t Poke(
            type_id,
            local_language_id,
            name
                
        );

        Pokenames.push_back(Poke);
        line = "";
    }


    displayTypeNames(Pokenames);

    return 0;
}

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

class moves_t {
public:
    moves_t()
    {

    }
    moves_t(
        int id,
        string identifier,
        int generation_id,
        int type_id,
        int power,
        int pp,
        int accuracy,
        int priority,
        int target_id,
        int damage_class_id,
        int effect_id,
        int effect_chance,
        int contest_type_id,
        int contest_effect_id,
        int super_contest_effect_id
    ) {
            this->id = id;         
            this->identifier = identifier;
            this->generation_id = generation_id;
            this->type_id = type_id;
            this->power = power;
            this->pp = pp;
             this->accuracy = accuracy;
            this->priority = priority;
            this->target_id = target_id;
            this->damage_class_id = damage_class_id;
            this->effect_id = effect_id;
            this->effect_chance = effect_chance;
            this->contest_type_id = contest_type_id;
            this->contest_effect_id = contest_effect_id;
            this->super_contest_effect_id = super_contest_effect_id;

    }

    void display() {
        cout << " Moves id: " << id << endl;
        cout << " Moves identifier: " << identifier << endl;
        cout << " Moves generation_id: " << generation_id << endl;
        cout << " Moves type_id: " << type_id << endl;
        cout << " Moves power: " << power << endl;
        cout << " Moves pp: " << pp << endl;
        cout << " Moves accuracy: " << accuracy << endl;
        cout << " Moves priority: " << priority << endl;
        cout << " Moves target_id: " << target_id << endl;
        cout << " Moves damage_class_id: " << damage_class_id << endl;
        cout << " Moves effect_id: " << effect_id << endl;
        cout << " Moves effect_chance: " << effect_chance << endl;
        cout << " Moves contest_type_id: " << contest_type_id << endl;
        cout << " Moves contest_effect_id: " << contest_effect_id << endl;
        cout << " Moves super_contest_effect_id: " << super_contest_effect_id << endl;

    }

    int id;    
    string identifier;
    int generation_id;
    int type_id;
    int power;
    int pp;    
    int accuracy;
    int priority;
    int target_id;
    int damage_class_id;
    int effect_id;
    int effect_chance;
    int contest_type_id;
    int contest_effect_id;
    int super_contest_effect_id;
};

void displayMoves(vector<moves_t>& moves)
{

        for(int i = 0; i < moves.size(); i++)
        {
            moves[i].display();
        }
    
}

int moves()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/moves.csv");
    string line;


    vector<moves_t> moves;
    
    int id;    
    string identifier;
    int generation_id;
    int type_id;
    int power;
    int pp;    
    int accuracy;
    int priority;
    int target_id;
    int damage_class_id;
    int effect_id;
    int effect_chance;
    int contest_type_id;
    int contest_effect_id;
    int super_contest_effect_id;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        

        getline(inputString, identifier, ',');


        getline(inputString, tempString, ',');
        generation_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        type_id = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        power = atoi(tempString.c_str());
        
        getline(inputString, tempString, ',');
        pp = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        accuracy = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        priority = atoi(tempString.c_str());
       

        getline(inputString, tempString, ',');
        target_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        damage_class_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        effect_id = atoi(tempString.c_str());


        getline(inputString, tempString, ',');
        effect_chance = atoi(tempString.c_str());


        getline(inputString, tempString, ',');
        contest_type_id = atoi(tempString.c_str());


        getline(inputString, tempString, ',');
        contest_effect_id = atoi(tempString.c_str());


        getline(inputString, tempString, ',');
        super_contest_effect_id = atoi(tempString.c_str());
        



        moves_t move(
            id,
            identifier,
            generation_id,
            type_id,
            power,
            pp,
            accuracy,
            priority,
            target_id,
            damage_class_id,
            effect_id,
            effect_chance,
            contest_type_id,
            contest_effect_id,
            super_contest_effect_id
        );

        moves.push_back(move);
        line = "";
    }


    displayMoves(moves);

    return 0;
}

class experience_t {
public:
    experience_t()
    {

    }
    experience_t(
        //growth_rate_id,level,experience
            int growth_rate_id,
            int level,
            int experienceInt
    ) {
       
        this->growth_rate_id = growth_rate_id;
        this->level = level;
        this->experienceInt = experienceInt;

    }

    void display() {
        
        cout << " Experience growth_rate_id: " << growth_rate_id << endl;
        cout << " Experience level: " << level << endl;
        cout << " Experience experience: " << experienceInt << endl;

    }

    
    int growth_rate_id;
    int level;
    int experienceInt;
};

void displayExperience(vector<experience_t>& experiences)
{

        for(int i = 0; i < experiences.size(); i++)
        {
            experiences[i].display();
        }
    
}

int experience()
{
    ifstream inputFile;
    inputFile.open("/Users/elmin/Downloads/poke327-s2021-1.05/experience.csv");
    string line;


    vector<experience_t> experiences;
   

    
    int growth_rate_id,level,experienceInt;

    string tempString;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        growth_rate_id = atoi(tempString.c_str());

        getline(inputString, tempString, ',');
        level = atoi(tempString.c_str());
        

        getline(inputString, tempString, ',');
        experienceInt = atoi(tempString.c_str());
        
        



        experience_t experience(
               growth_rate_id,
            level,
             experienceInt
                
        );

        experiences.push_back(experience);
        line = "";
    }


    displayExperience(experiences);

    return 0;
}

static int32_t path_cmp(const void *key, const void *with) {
  return ((path_t *) key)->cost - ((path_t *) with)->cost;
}

static int32_t edge_penalty(int8_t x, int8_t y)
{
  return (x == 1 || y == 1 || x == MAP_X - 2 || y == MAP_Y - 2) ? 2 : 1;
}

static void dijkstra_path(map_t *m, pair_t from, pair_t to)
{
  static path_t path[MAP_Y][MAP_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < MAP_Y; y++) {
      for (x = 0; x < MAP_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, path_cmp, NULL);

  for (y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      path[y][x].hn = heap_insert(&h, &path[y][x]);
    }
  }

  while ((p = (path_t *)heap_remove_min(&h))) {
    p->hn = NULL;

    if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
      for (x = to[dim_x], y = to[dim_y];
           (x != from[dim_x]) || (y != from[dim_y]);
           p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
        mapxy(x, y) = ter_path;
        heightxy(x, y) = 0;
      }
      heap_delete(&h);
      return;
    }

    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1)))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1));
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] - 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] + 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }
  }
}

static int build_paths(map_t *m)
{
  pair_t from, to;

  /*  printf("%d %d %d %d\n", m->n, m->s, m->e, m->w);*/

  if (m->e != -1 && m->w != -1) {
    from[dim_x] = 1;
    to[dim_x] = MAP_X - 2;
    from[dim_y] = m->w;
    to[dim_y] = m->e;

    dijkstra_path(m, from, to);
  }

  if (m->n != -1 && m->s != -1) {
    from[dim_y] = 1;
    to[dim_y] = MAP_Y - 2;
    from[dim_x] = m->n;
    to[dim_x] = m->s;

    dijkstra_path(m, from, to);
  }

  if (m->e == -1) {
    if (m->s == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->w == -1) {
    if (m->s == -1) {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->n == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->s == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    }

    dijkstra_path(m, from, to);
  }

  return 0;
}

static int gaussian[5][5] = {
  {  1,  4,  7,  4,  1 },
  {  4, 16, 26, 16,  4 },
  {  7, 26, 41, 26,  7 },
  {  4, 16, 26, 16,  4 },
  {  1,  4,  7,  4,  1 }
};

static int smooth_height(map_t *m)
{
  int32_t i, x, y;
  int32_t s, t, p, q;
  queue_node_t *head, *tail, *tmp;
  /*  FILE *out;*/
  uint8_t height[MAP_Y][MAP_X];

  memset(&height, 0, sizeof (height));

  /* Seed with some values */
  for (i = 1; i < 255; i += 20) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (height[y][x]);
    height[y][x] = i;
    if (i == 1) {
      head = tail = (queue_node_t *)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);
  */
  
  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = height[y][x];

    if (x - 1 >= 0 && y - 1 >= 0 && !height[y - 1][x - 1]) {
      height[y - 1][x - 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y - 1;
    }
    if (x - 1 >= 0 && !height[y][x - 1]) {
      height[y][x - 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y;
    }
    if (x - 1 >= 0 && y + 1 < MAP_Y && !height[y + 1][x - 1]) {
      height[y + 1][x - 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y + 1;
    }
    if (y - 1 >= 0 && !height[y - 1][x]) {
      height[y - 1][x] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y - 1;
    }
    if (y + 1 < MAP_Y && !height[y + 1][x]) {
      height[y + 1][x] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y + 1;
    }
    if (x + 1 < MAP_X && y - 1 >= 0 && !height[y - 1][x + 1]) {
      height[y - 1][x + 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y - 1;
    }
    if (x + 1 < MAP_X && !height[y][x + 1]) {
      height[y][x + 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y;
    }
    if (x + 1 < MAP_X && y + 1 < MAP_Y && !height[y + 1][x + 1]) {
      height[y + 1][x + 1] = i;
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y + 1;
    }

    tmp = head;
    head = head->next;
    free(tmp);
  }

  /* And smooth it a bit with a gaussian convolution */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }
  /* Let's do it again, until it's smooth like Kenny G. */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);

  out = fopen("smoothed.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->height, sizeof (m->height), 1, out);
  fclose(out);
  */

  return 0;
}

static void find_building_location(map_t *m, pair_t p)
{
  do {
    p[dim_x] = rand() % (MAP_X - 5) + 3;
    p[dim_y] = rand() % (MAP_Y - 10) + 5;

    if ((((mapxy(p[dim_x] - 1, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] - 1, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x] + 2, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] + 2, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] - 1) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] - 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] + 2) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 2) == ter_path)))   &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_center))) &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_path)))) {
          break;
    }
  } while (1);
}

static int place_pokemart(map_t *m)
{
  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_mart;

  return 0;
}

static int place_center(map_t *m)
{  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_center;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_center;

  return 0;
}

static int map_terrain(map_t *m, int8_t n, int8_t s, int8_t e, int8_t w)
{
  int32_t i, x, y;
  queue_node_t *head, *tail, *tmp;
  //  FILE *out;
  int num_grass, num_clearing, num_mountain, num_forest, num_total;
  terrain_type_t type;
  int added_current = 0;
  
  num_grass = rand() % 4 + 2;
  num_clearing = rand() % 4 + 2;
  num_mountain = rand() % 2 + 1;
  num_forest = rand() % 2 + 1;
  num_total = num_grass + num_clearing + num_mountain + num_forest;

  memset(&m->map, 0, sizeof (m->map));

  /* Seed with some values */
  for (i = 0; i < num_total; i++) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (m->map[y][x]);
    if (i == 0) {
      type = ter_grass;
    } else if (i == num_grass) {
      type = ter_clearing;
    } else if (i == num_grass + num_clearing) {
      type = ter_mountain;
    } else if (i == num_grass + num_clearing + num_mountain) {
      type = ter_forest;
    }
    m->map[y][x] = type;
    if (i == 0) {
      head = tail = (queue_node_t *)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t *)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */

  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = m->map[y][x];
    
    if (x - 1 >= 0 && !m->map[y][x - 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x - 1] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x - 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y - 1 >= 0 && !m->map[y - 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y - 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y - 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y + 1 < MAP_Y && !m->map[y + 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y + 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y + 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (x + 1 < MAP_X && !m->map[y][x + 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x + 1] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x + 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t *)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    added_current = 0;
    tmp = head;
    head = head->next;
    free(tmp);
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (y == 0 || y == MAP_Y - 1 ||
          x == 0 || x == MAP_X - 1) {
        mapxy(x, y) = ter_boulder;
      }
    }
  }

  m->n = n;
  m->s = s;
  m->e = e;
  m->w = w;

  if (n != -1) {
    mapxy(n,         0        ) = ter_exit;
    mapxy(n,         1        ) = ter_path;
  }
  if (s != -1) {
    mapxy(s,         MAP_Y - 1) = ter_exit;
    mapxy(s,         MAP_Y - 2) = ter_path;
  }
  if (w != -1) {
    mapxy(0,         w        ) = ter_exit;
    mapxy(1,         w        ) = ter_path;
  }
  if (e != -1) {
    mapxy(MAP_X - 1, e        ) = ter_exit;
    mapxy(MAP_X - 2, e        ) = ter_path;
  }

  return 0;
}

static int place_boulders(map_t *m)
{
  int i;
  int x, y;

  for (i = 0; i < MIN_BOULDERS || rand() % 100 < BOULDER_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_forest && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_boulder;
    }
  }

  return 0;
}

static int place_trees(map_t *m)
{
  int i;
  int x, y;
  
  for (i = 0; i < MIN_TREES || rand() % 100 < TREE_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_mountain && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_tree;
    }
  }

  return 0;
}

void rand_pos(pair_t pos)
{
  pos[dim_x] = (rand() % (MAP_X - 2)) + 1;
  pos[dim_y] = (rand() % (MAP_Y - 2)) + 1;
}

void new_hiker()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.hiker_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t *)malloc(sizeof (*c));
  c->npc = (npc_t *)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_hiker;
  c->npc->mtype = move_hiker;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'h';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);

  //  printf("Hiker at %d,%d\n", pos[dim_x], pos[dim_y]);
}

void new_rival()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t *)malloc(sizeof (*c));
  c->npc = (npc_t *)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_rival;
  c->npc->mtype = move_rival;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'r';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void new_char_other()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t *)malloc(sizeof (*c));
  c->npc = (npc_t *)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_other;
  switch (rand() % 4) {
  case 0:
    c->npc->mtype = move_pace;
    c->symbol = 'p';
    break;
  case 1:
    c->npc->mtype = move_wander;
    c->symbol = 'w';
    break;
  case 2:
    c->npc->mtype = move_sentry;
    c->symbol = 's';
    break;
  case 3:
    c->npc->mtype = move_walk;
    c->symbol = 'n';
    break;
  }
  rand_dir(c->npc->dir);
  c->npc->defeated = 0;
  c->pc = NULL;
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void place_characters()
{
  world.cur_map->num_trainers = 2;

  //Always place a hiker and a rival, then place a random number of others
  new_hiker();
  new_rival();
  do {
    //higher probability of non- hikers and rivals
    switch(rand() % 10) {
    case 0:
      new_hiker();
      break;
    case 1:
     new_rival();
      break;
    default:
      new_char_other();
      break;
    }
  } while (++world.cur_map->num_trainers < MIN_TRAINERS ||
           ((rand() % 100) < ADD_TRAINER_PROB));
}

void init_pc()
{
  int x, y;

  do {
    x = rand() % (MAP_X - 2) + 1;
    y = rand() % (MAP_Y - 2) + 1;
  } while (world.cur_map->map[y][x] != ter_path);

  world.pc.pos[dim_x] = x;
  world.pc.pos[dim_y] = y;
  world.pc.symbol = '@';
  world.pc.pc = (pc_t *)malloc(sizeof (*world.pc.pc));
  world.pc.npc = NULL;

  world.cur_map->cmap[y][x] = &world.pc;
  world.pc.next_turn = 0;

  heap_insert(&world.cur_map->turn, &world.pc);
}

void place_pc()
{
  character_t *c;

  if (world.pc.pos[dim_x] == 1) {
    world.pc.pos[dim_x] = MAP_X - 2;
  } else if (world.pc.pos[dim_x] == MAP_X - 2) {
    world.pc.pos[dim_x] = 1;
  } else if (world.pc.pos[dim_y] == 1) {
    world.pc.pos[dim_y] = MAP_Y - 2;
  } else if (world.pc.pos[dim_y] == MAP_Y - 2) {
    world.pc.pos[dim_y] = 1;
  }

  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;

  if ((c = (character_t *)heap_peek_min(&world.cur_map->turn))) {
    world.pc.next_turn = c->next_turn;
  } else {
    world.pc.next_turn = 0;
  }
}

// New map expects cur_idx to refer to the index to be generated.  If that
// map has already been generated then the only thing this does is set
// cur_map.
int new_map(int teleport)
{
  int d, p;
  int e, w, n, s;
  int x, y;
  
  if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]]) {
    world.cur_map = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]];
    place_pc();

    return 0;
  }

  world.cur_map                                             =
    world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]] =
    (map_t *)malloc(sizeof (*world.cur_map));

  smooth_height(world.cur_map);
  
  if (!world.cur_idx[dim_y]) {
    n = -1;
  } else if (world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]) {
    n = world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]->s;
  } else {
    n = 3 + rand() % (MAP_X - 6);
  }
  if (world.cur_idx[dim_y] == WORLD_SIZE - 1) {
    s = -1;
  } else if (world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]) {
    s = world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]->n;
  } else  {
    s = 3 + rand() % (MAP_X - 6);
  }
  if (!world.cur_idx[dim_x]) {
    w = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]) {
    w = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]->e;
  } else {
    w = 3 + rand() % (MAP_Y - 6);
  }
  if (world.cur_idx[dim_x] == WORLD_SIZE - 1) {
    e = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]) {
    e = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]->w;
  } else {
    e = 3 + rand() % (MAP_Y - 6);
  }
  
  map_terrain(world.cur_map, n, s, e, w);
     
  place_boulders(world.cur_map);
  place_trees(world.cur_map);
  build_paths(world.cur_map);
  d = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
       abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)));
  p = d > 200 ? 5 : (50 - ((45 * d) / 200));
  //  printf("d=%d, p=%d\n", d, p);
  if ((rand() % 100) < p || !d) {
    place_pokemart(world.cur_map);
  }
  if ((rand() % 100) < p || !d) {
    place_center(world.cur_map);
  }

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      world.cur_map->cmap[y][x] = NULL;
    }
  }

  heap_init(&world.cur_map->turn, cmp_char_turns, delete_character);

  if ((world.cur_idx[dim_x] == WORLD_SIZE / 2) &&
      (world.cur_idx[dim_y] == WORLD_SIZE / 2)) {
    init_pc();
  } else {
    place_pc();
  }

  pathfind(world.cur_map);
  if (teleport) {
    do {
      world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;
      world.pc.pos[dim_x] = rand_range(1, MAP_X - 2);
      world.pc.pos[dim_y] = rand_range(1, MAP_Y - 2);
    } while (world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ||
             (move_cost[char_pc][world.cur_map->map[world.pc.pos[dim_y]]
                                                   [world.pc.pos[dim_x]]] ==
              INT_MAX)                                                      ||
             world.rival_dist[world.pc.pos[dim_y]][world.pc.pos[dim_x]] < 0);
    world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;
    pathfind(world.cur_map);
  }
  
  place_characters();

  return 0;
}

/*
static void print_map()
{
  int x, y;
  int default_reached = 0;

  printf("\n\n\n");

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.cur_map->cmap[y][x]) {
        putchar(world.cur_map->cmap[y][x]->symbol);
      } else {
        switch (world.cur_map->map[y][x]) {
        case ter_boulder:
        case ter_mountain:
          putchar('%');
          break;
        case ter_tree:
        case ter_forest:
          putchar('^');
          break;
        case ter_path:
          putchar('#');
          break;
        case ter_mart:
          putchar('M');
          break;
        case ter_center:
          putchar('C');
          break;
        case ter_grass:
          putchar(':');
          break;
        case ter_clearing:
          putchar('.');
          break;
        default:
          default_reached = 1;
          break;
        }
      }
    }
    putchar('\n');
  }

  if (default_reached) {
    fprintf(stderr, "Default reached in %s\n", __FUNCTION__);
  }
}
*/

// The world is global because of its size, so init_world is parameterless
void init_world()
{
  world.quit = 0;
  world.cur_idx[dim_x] = world.cur_idx[dim_y] = WORLD_SIZE / 2;
  new_map(0);
}

void delete_world()
{
  int x, y;

  //Only correct because current game never leaves the initial map
  //Need to iterate over all maps in 1.05+
  heap_delete(&world.cur_map->turn);

  for (y = 0; y < WORLD_SIZE; y++) {
    for (x = 0; x < WORLD_SIZE; x++) {
      if (world.world[y][x]) {
        free(world.world[y][x]);
        world.world[y][x] = NULL;
      }
    }
  }
}

void print_hiker_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.hiker_dist[y][x] == INT_MAX) {
        printf("   ");
      } else {
        printf(" %5d", world.hiker_dist[y][x]);
      }
    }
    printf("\n");
  }
}

void print_rival_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.rival_dist[y][x] == INT_MAX || world.rival_dist[y][x] < 0) {
        printf("   ");
      } else {
        printf(" %02d", world.rival_dist[y][x] % 100);
      }
    }
    printf("\n");
  }
}

void leave_map(pair_t d)
{
  if (d[dim_x] == 0) {
    world.cur_idx[dim_x]--;
  } else if (d[dim_y] == 0) {
    world.cur_idx[dim_y]--;
  } else if (d[dim_x] == MAP_X - 1) {
    world.cur_idx[dim_x]++;
  } else {
    world.cur_idx[dim_y]++;
  }
  new_map(0);
}

void game_loop()
{
  character_t *c;
  pair_t d;
  
  while (!world.quit) {
    c = (character_t *)heap_remove_min(&world.cur_map->turn);

    move_func[c->npc ? c->npc->mtype : move_pc](c, d);

    world.cur_map->cmap[c->pos[dim_y]][c->pos[dim_x]] = NULL;
    if (c->pc && (d[dim_x] == 0 || d[dim_x] == MAP_X - 1 ||
                  d[dim_y] == 0 || d[dim_y] == MAP_Y - 1)) {
      leave_map(d);
      d[dim_x] = c->pos[dim_x];
      d[dim_y] = c->pos[dim_y];
    }
    world.cur_map->cmap[d[dim_y]][d[dim_x]] = c;

    if (c->pc) {
      // Performance bug - pathfinding runs twice after generating a new map
      pathfind(world.cur_map);
    }

    c->next_turn += move_cost[c->npc ? c->npc->ctype : char_pc]
                             [world.cur_map->map[d[dim_y]][d[dim_x]]];

    c->pos[dim_y] = d[dim_y];
    c->pos[dim_x] = d[dim_x];

    heap_insert(&world.cur_map->turn, c);
  }
}

int main(int argc, char *argv[])
{
// pokemon, moves, pokemon moves,
// pokemon species, experience, or type names.

  string command;

  

    while(1)
    {

      cout << "Commands: pokemon, moves, pokemon_moves, pokemon_species, experience, or type_names. |Q to quit|" << endl;
      cout << "Enter: ";
      cin >> command;


      if(command.compare("pokemon"))
      {
        pokemon();
      }
      else if(command.compare("moves"))
      {
        moves();
      }
      else if(command.compare("pokemon_moves"))
      {
        pokemon_moves();
      }
      else if(command.compare("pokemon_species"))
      {
        pokemon_species();
      }
      else if(command.compare("experience"))
      {
        experience();
      }
      else if(command.compare("type_names"))
      {
        type_names();
      }
      else if(command.compare("Q"))
      {
        return 0;
      }
      else
      {
        cout << "Error not correct command" << endl;
      }
    }



    type_names();
    return 0;
    
  struct timeval tv;
  uint32_t seed;
  //  char c;
  //  int x, y;

  if (argc == 2) {
    seed = atoi(argv[1]);
  } else {
    gettimeofday(&tv, NULL);
    seed = (tv.tv_usec ^ (tv.tv_sec << 20)) & 0xffffffff;
  }

  printf("Using seed: %u\n", seed);
  srand(seed);

  io_init_terminal();
  
  init_world();

  /* print_hiker_dist(); */
  
  /*
  do {
    print_map();  
    printf("Current position is %d%cx%d%c (%d,%d).  "
           "Enter command: ",
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S',
           world.cur_idx[dim_x] - (WORLD_SIZE / 2),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2));
    scanf(" %c", &c);
    switch (c) {
    case 'n':
      if (world.cur_idx[dim_y]) {
        world.cur_idx[dim_y]--;
        new_map();
      }
      break;
    case 's':
      if (world.cur_idx[dim_y] < WORLD_SIZE - 1) {
        world.cur_idx[dim_y]++;
        new_map();
      }
      break;
    case 'e':
      if (world.cur_idx[dim_x] < WORLD_SIZE - 1) {
        world.cur_idx[dim_x]++;
        new_map();
      }
      break;
    case 'w':
      if (world.cur_idx[dim_x]) {
        world.cur_idx[dim_x]--;
        new_map();
      }
      break;
     case 'q':
      break;
    case 'f':
      scanf(" %d %d", &x, &y);
      if (x >= -(WORLD_SIZE / 2) && x <= WORLD_SIZE / 2 &&
          y >= -(WORLD_SIZE / 2) && y <= WORLD_SIZE / 2) {
        world.cur_idx[dim_x] = x + (WORLD_SIZE / 2);
        world.cur_idx[dim_y] = y + (WORLD_SIZE / 2);
        new_map();
      }
      break;
    case '?':
    case 'h':
      printf("Move with 'e'ast, 'w'est, 'n'orth, 's'outh or 'f'ly x y.\n"
             "Quit with 'q'.  '?' and 'h' print this help message.\n");
      break;
    default:
      fprintf(stderr, "%c: Invalid input.  Enter '?' for help.\n", c);
      break;
    }
  } while (c != 'q');

  */

  game_loop();
  
  delete_world();

  io_reset_terminal();
  
  return 0;
}
