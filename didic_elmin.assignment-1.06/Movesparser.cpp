//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


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


