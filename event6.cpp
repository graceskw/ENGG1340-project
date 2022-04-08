//EVENT2 - Get Firewoods
#include <iostream>
using namespace std;
#include "roll.h"

int main(){
    string input;

    while(1){
        cout << "You found a firewood laying on the ground. Pick it up? (Y/N)" << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
        cout << "pickup" << endl;
        //pickup
        break;
        }else if(input == "N" || input == "n"){
        //leave it
        break;
        }else{
            cout << "invalid input" << endl;
        }
    }
}