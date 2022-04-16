#include <iostream>
#include <string>
#include "map.h"
#include "events.h"
using namespace std;

int main(){
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
            // open and output commands.txt
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
        else if(input=="look"){
            // replay the dialogues in each scene
            valid = true;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }while(valid == false);

    return 0;
}
