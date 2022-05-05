#include <iostream>
#include <vector>
#include "commands.h"
#include "map.h"
#include "roll.h"
#include "scenes.h"
using namespace std;

void beginning(Position &player, vector<vector<char>> &map, SceneChange &sceneChange){
    string input;
    checkScene(player, sceneChange);

    // scene dialogue
    cout << "BANG \"Damn!\"" << endl;
    cout << "Your car broke down. In the middle of a forest." << endl;
    cout << "\"I\'m sorry Hest, but it looks like we have to find a place to stay for the night\"" << endl;
    cout << "Furrowing your eyebrows, you reluctantly agreed. What a great way to start your anniversary trip. But what could you do?" << endl;
    cout << "You hopped off the car, squinting your eyes, hoping to find a residence in the dense forest." << endl;

	Printmap(player, map);

    cout << "\"Why would there be any houses in the middle of nowhere?\" you thought to yourself." << endl;
    cout << "You: x\nPossible directions: W (or w) ";
    cin >> input;
    string dir_w="wW", dir_s="sS", dir="wsWS";
    
    // 
    while(dir_w.find(input) == std::string::npos){
        cout << "Invalid input." << endl;
        cout << "You: x\nPossible directions: W (or w) ";
        cin >> input;
    }
    player.x = 4;
    player.y = 6;
    
    while(player.y != 3){
        if(player.x == 4 && player.y == 6){
            Printmap(player, map);
            cout << "\"Honey, are you sure we should keep going?\"" << endl; 
            cout << "Fidgeting with your lucky charm nervously, you asked Asher." << endl;
            cout << "You: x\nPossible directions: W (or w) ";
            
            cin >> input;
            while(dir_w.find(input) == std::string::npos){
                cout << "Invalid input." << endl;
                cout << "You: x\nPossible directions: W (or w) ";
                cin >> input;
            }
            if(dir_w.find(input)!=std::string::npos){
                player.y = 5;
            }
        }

        if(player.x == 4 && player.y == 5){
            Printmap(player, map);
            cout << "You: x\nPossible directions: W (or w), S (or s) ";
            
            cin >> input;
            while(dir.find(input) == std::string::npos){
                cout << "Invalid input." << endl;
                cout << "You: x\nPossible directions: W (or w), S (or s) ";
                cin >> input;
            }
            if(dir_w.find(input)!=std::string::npos){
                player.y = 4;
            }
            else{
                player.y = 6;
            }

        }
        if(player.x == 4 && player.y == 4){
            Printmap(player, map);
            cout << "\"I think we should turn back.\" \"Just trust me Hest.\"" << endl;
            cout << "You: x\nPossible directions: W (or w), S (or s) ";

            cin >> input;
            while(dir.find(input) == std::string::npos){
                cout << "Invalid input." << endl;
                cout << "You: x\nPossible directions: W (or w), S (or s) ";
                cin >> input;
            }
            if(dir_w.find(input)!=std::string::npos){
                player.y = 3;
            }
            else if(dir_s.find(input)!=std::string::npos){
                player.y = 5;
            }

        }
    }

    Printmap(player, map);
    cout << "\"There!\" Asher exclaimed, \"I told you, a house!\"" << endl;
    cout << "Under the dim lights of the silver moon, the house seems perfect for the setting of a murder mystery." << endl;
    cout << "A chill was sent down your spine. You were hesitant to step inside." << endl;
    cout << "\"Let fate decide for us.\" You mumbled." << endl;

    cout << "You roll the dice you have been holding to determine your action (>=3):  (type dice to roll)" << endl;
    roll_dice(0);           // must be >=3

    cout << "Though sceptical, you had to seek shelter before you two froze to death.\n" << endl;
    player.y = 2;
    sceneChange.change = 1;
    sceneChange.direction = 'w';
    checkScene(player, sceneChange);
}