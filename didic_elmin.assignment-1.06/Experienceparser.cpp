//
// Created by Elmin Didic on 3/29/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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


