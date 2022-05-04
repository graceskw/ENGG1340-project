// havent implement: movement, help, map, items(inventory)<-maybe use vector here

#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "events.h"
#include "commands.h"
#include "inventory.h"
using namespace std;

void commands(Position player, vector<vector<char>> map, SceneChange &sceneChange, Inventory &inventory){
    string input;
    bool valid=false;
    
    do{
        cout << "Enter a command (type help for a list of commands): ";
        cin >> input;

        if(input.find("wasdWASD") != NULL){
            cout << player.x << player.y << endl;
            player = Movement(input, player, map, sceneChange);	
            if(sceneChange.change){
                cout << "changescene" << endl;
                checkScene(player, sceneChange);
                generatemap(player, map);
            }
            valid = true;   
        }
        else if(input == "help"){
            ifstream fin;
            fin.open("commands.txt");

            // output contents of file

            valid = true;
        }
        else if(input == "map"){
            Printmap(player, map);
            valid = true;           
        }
        else if(input == "grab"){
            cout << "You can't see anything to grab.";
            valid = true;
        }
        else if(input == "use"){
            cout << "You can't use anything here.";
            valid = true;
        }
        else if(input == "items"){                          // list items in the inventory
            if(inventory.firewood && inventory.key){
                cout << "You have:" << endl;
                if(inventory.firewood){
                    cout << "Firewood * 1" << endl;
                }
                if(inventory.key){
                    cout << "key * 1" << endl;
                }
            }
            else{
                cout << "You don\'t have any items in your pockets." << endl;
            }
        }
        else{
            cout << "Invalid input." << endl;
        }
    }while(valid == false);
}
