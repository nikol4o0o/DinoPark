#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "Dino.h"
#include "Dinomass.h"
#include "Cage.h"
#include "Cagemass.h"


using namespace std;

char* TransformcladeToClimateNeeded(char* clade, char* climatebydino);


int main()
{
    char name[256];
    bool gender;///1-male, 0-female
    char era[128];
    char clade[64];
    char category[32];
    char food[32];
    size_t size;
    char climate[32];
    Dinomass dinosinthecage[10];
    char erainthecage[64];
    Dinomass dinosaurs;
    Cagemass cages;
    char climatebydino[32];
    vector<const char*> foods;

    ifstream Dinosipnut("Dinos.txt");
    dinosaurs.readDinos(Dinosipnut);

    ifstream Cagesinput("Cages.txt");
    cages.readCages(Cagesinput);
    printf("Welcome to the DinoPark!\n");
    printf("If you are new just type 'help' on the console\n");


    char command[16];
    cin.getline(command, 15);

    while (strcmp(command, "exit") != 0)
    {
        if (strcmp(command, "help") == 0)
        {
            cout << "Supported commands are:" << endl;
            cout << "add dino - adds dino" << endl;
            cout << "add cage - adds cage" << endl;
            cout << "remove dino - removes dino" << endl;
            cout << "food supply - generates food for every dino" << endl;
            cout << "exit - ends the program" << endl;

        }
        if (strcmp(command, "add dino") == 0)
        {
            cout << "Enter the name: " << endl;
            cin.getline(name, 256);
            cout << "Enter the era: (Trias/Creda/Ura) " << endl;
            cin.getline(era, 128);
            cout << "Enter the clade: (Trevopasen/Mesoqden/Letqsht/Voden) " << endl;
            cin.getline(clade, 64);
            cout << "Enter the category: " << endl;
            cin.getline(category, 32);
            cout << "Enter the food: (grass/ meat/ fish)" << endl;
            cin >> food;
            cout << "Enter the gender: (1-male/ 0- female) " << endl;
            cin >> gender;
            TransformcladeToClimateNeeded(clade, climatebydino);
            cout << climatebydino << endl;
            

            Dino dino(name, gender, era, clade,category, food, climatebydino);
            dinosaurs.AddDino(dino);
            cout << dino.getClimate() << endl;
            
                if (cages.getSize() > 0)
                {
                    bool flag = false;
                    for (int i = 0; i < cages.getSize(); i++)
                    {
                        if (cages[i].havespace())
                        {
                            if ((strcmp(cages[i].getClimate(), dino.getClimate()) == 0) && (strcmp(cages[i].getErainthecage(), dino.getEra()) == 0))
                            {
                                cages[i].AddDinosinthecage(dino);
                                cout << "Successfully added" << endl;
                                flag = true;
                            }
                        }
                    }
                    if (flag == false)
                    {
                        cout << "There is no space! Enter the size of the new cage" << endl;
                        cin >> size;
                        Cage newcage(size, dino.getClimate(), dino.getEra());
                        cages.AddCage(newcage);
                        newcage.AddDinosinthecage(dino);
                    }
                        
                }
                else if (cages.getSize() == 0)
                {
                    cout << "Enter the size of the new cage" << endl;
                    cin >> size ;
                    Cage newcage(size, dino.getClimate(), dino.getEra());
                    cages.AddCage(newcage);
                    newcage.AddDinosinthecage(dino);

                }
           
        }

        if (strcmp(command, "add cage") == 0)
        {
            cout << "Enter the climate: (Voden/Suhozemen/Vuzdushen) " << endl;
            cin.getline(climate, 31);
            cout << "Enter the era in the cage: (Trias/Creda/Ura) " << endl;
            cin.getline(erainthecage, 63);
            cout << "Enter the size of the cage: " << endl;
            cin >> size;

            Cage cage(size, climate, erainthecage);
            cages.AddCage(cage);
            cout << "Successfull!" << endl;

        }

        if (strcmp(command, "food supply") == 0)
        {
            for (int i = 0; i < dinosaurs.getsize(); i++)
            {
                foods.push_back(dinosaurs[i].getFood());
            }
            cout << "Successfully loaded! Now there is food for everyone!" << endl;
        }

        if (strcmp(command, "remove dino") == 0)
        {
            cout << "Enter the name of the dino you would like to remove" << endl;
            cin.getline(name, 255);
            dinosaurs.DeleteDino(name);
        }




        cin.getline(command, 15);
    }
    

    ofstream Dinosoutput("Dinos.txt");
    dinosaurs.saveDinos(Dinosoutput);
    ofstream Cagesoutput("Cages.txt");
    cages.saveCages(Cagesoutput);

}
char* TransformcladeToClimateNeeded(char* clade, char* climatebydino)
{
    if ((strcmp(clade, "Trevopasen") == 0) || (strcmp(clade, "Mesoqden") == 0))
    {
        strcpy_s(climatebydino, 31, "Suhozemen");
        return climatebydino;
    }
    else if (strcmp(clade, "Voden") == 0)
    {
        strcpy_s(climatebydino, 31, "Voden");
        return climatebydino;
    }
    else
    {
        strcpy_s(climatebydino, 31, "Vuzdushen");
        return climatebydino;
    }
}


