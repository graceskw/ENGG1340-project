// need implement ending scenes
// maybe combine with beginning in scenes
// room 5 trigger

#include <iostream>
#include "events.h"
#include "roll.h"
#include "scenes.h"
using namespace std;


void ending1(){     // Good ending



}

void ending2(){     // Bad ending



}

// maybe integrate progress in events if have time
void final(EventProgress eventprogress){
    int progress=0;                         // count number of successful events
    if(eventprogress.event1){
        progress++;
    }
    if(eventprogress.event2){
        progress++;
    }
    if(eventprogress.event3){
        progress++;
    }
    if(eventprogress.event4){
        progress++;
    }
    if(eventprogress.event5){
        progress++;
    }

    if(progress >= 3){                      // the ending is dependent on the number of successful events
        ending1();
    }
    else{
        ending2();
    }
}