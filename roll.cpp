// Program for dice rolling
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
#include "roll.h"

int roll_dice(int event_num){
    srand(time(0));
    int random;

    if(event_num == 0){
        random  = rand()%4+3;
    }
    else{
        random  = rand()%6+1;
    }

    return random;
}
