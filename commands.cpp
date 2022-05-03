// havent implement: movement, help, map, items(inventory)<-maybe use vector here

#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "events.h"
#include "commands.h"
using namespace std;

void commands(){
    string input;
    bool valid=false;
    
    do{
        cout << "Enter a command (type help for a list of commands): ";
        cin >> input;

        if(input.find("wasdWASD") != NULL){
            // Position Movement(){
            valid = true;   
        }
        else if(input=="help"){
            ifstream fin;
            fin.open("commands.txt");

            // output contents of file

            valid = true;
        }
        else if(input=="map"){
            // output map
            valid = true;           
        }
        else if(input=="grab"){
            cout << "You can't see anything to grab.";
            valid = true;
        }
        else if(input=="use"){
            cout << "You can't use anything here.";
            valid = true;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }while(valid == false);
}
