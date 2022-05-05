// Program for dice rolling
#include <iostream>
#include <random>
#include <ctime>
#include "roll.h"
using namespace std;

bool roll_dice(int event_num){
    // initialise seed using time
    srand(time(0));
    int roll;

    string dice;
    cin >> dice;
    // roll dice
    while(dice != "dice"){
        cout << "Invalid input." << endl;
        cin >> dice;
    }
    
    if(dice == "dice"){
        if(event_num == 0){             // for beginning and ending scenes
            roll  = rand()%4+3;         // generate a random number from 3-6
            cout << "You rolled a " << roll << endl;
            return true;
        }
        else{                           // for events
            roll  = rand()%6+1;         // generate a random number from 1 to 6
            cout << "You rolled a " << roll << endl;
            if(roll >= 3){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
