//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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


