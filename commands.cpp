#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include "commands.h"
#include "events.h"
#include "inventory.h"
#include "map.h"
using namespace std;

void commands(Position &player, vector<vector<char>> map, SceneChange &sceneChange, vector <Inventory> inventory, EventProgress eventProgress){
    string input;
    bool valid=false;
    
    do{
        cout << "Enter a command (type help for a list of commands): ";
        cin >> input;
        string dir="wasdWASD";

        // movement of player
        if(dir.find(input) != std::string::npos){
            player = Movement(input, player, map, sceneChange);	
            // change of scene, generate new map each time
            if(sceneChange.change){
                checkScene(player, sceneChange);
                generatemap(player, map, eventProgress);
            }
            valid = true;   
        }
        // output the list of commands stored in commands.txt
        else if(input == "help"){
            ifstream fin;
            fin.open("commands.txt");

            string line;
            while(getline(fin, line)){
                cout << line << endl;
            }

            fin.close();
            valid = true;
        }
        // output current map
        else if(input == "map"){
        	generatemap(player, map, eventProgress);
            Printmap(player, map);
            valid = true;           
        }
        // grab an item
        else if(input == "grab"){
            cout << "You can't see anything to grab.\n";
            valid = true;
        }
        // use an item
        else if(input == "use"){
            cout << "You can't use anything here.\n";
            valid = true;
        }
        // list items in the inventory
        else if(input == "items"){                          
            if(!inventory.empty()){
                cout << "You have:" << endl;
                vector <Inventory>::iterator itr;
                for(itr=inventory.begin(); itr!=inventory.end(); itr++){
                    cout << itr->item << " * " << itr->number << endl;
                }
            }
            else{
                cout << "You don\'t have any items in your pockets." << endl;
            }
        }
        // roll dice
        else if(input == "dice"){
            srand(time(0));
            cout << "You take your dice from your pockets and rolled a " << rand()%6+1 << endl;
            cout << "You wonder what power does this danity object holds." << endl;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }while(valid == false);
}
