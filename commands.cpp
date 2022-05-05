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

        if(dir.find(input) != std::string::npos){
           // cout << player.x << " " << player.y << endl;
            player = Movement(input, player, map, sceneChange);	
           // cout << player.x << " " << player.y << endl;
            if(sceneChange.change){
              //  cout << "changescene" << endl;
                checkScene(player, sceneChange);
                generatemap(player, map, eventProgress);
            }
            valid = true;   
        }
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
        else if(input == "map"){        //delete?
        	generatemap(player, map, eventProgress);
            Printmap(player, map);
            valid = true;           
        }
        else if(input == "grab"){
            cout << "You can't see anything to grab.\n";
            valid = true;
        }
        else if(input == "use"){
            cout << "You can't use anything here.\n";
            valid = true;
        }
        else if(input == "items"){                          // list items in the inventory
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
