// Program for dice rolling
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
#include "roll.h"

bool roll_dice(int event_num){
    srand(time(0));
    int roll;

    string dice;
    cin >> dice;
    // roll dice
    if(dice == "dice"){
        if(event_num == 0){
            roll  = rand()%4+3;
            cout << "You rolled a " << roll << endl;
            return true;
        }
        else{
            roll  = rand()%6+1;
            cout << "You rolled a " << roll << endl;
            if(roll >= 3){
                return true;
            }
            else{
                return false;
            }
        }



    // return roll;
}
