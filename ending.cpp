// need implement ending scenes
// maybe combine with beginning in scenes
// room 5 trigger

#include <iostream>
#include <unistd.h>
#include <chrono>
#include "events.h"
#include "roll.h"
#include "scenes.h"
#include "roll.cpp"         // for testing
#include "events.cpp"       // for testing
using namespace std;


void ending1(EventProgress eventprogress){     // Good ending
    // evidence
    if(eventprogress.event1){
    
        cout << "The newspaper. ";
    }
    if(eventprogress.event2){
        cout << "The fireplace. ";
    }
    if(eventprogress.event3){
        cout << "The empty knife holder and the instructions. ";
    }
    if(eventprogress.event4){
        cout << "The Kit chocolate. ";
    }
    if(eventprogress.event5){
        cout << "The diary. ";
    }

    cout << "\n\nIt all links up now.\n" << endl;
    cout << "You can feel the fury kindling within you. The love you once had for Asher now becomes pure hatred, so pure it is the perfect fuel for your growing desire. You desire to burn this house AND this man into ashes." << endl;

    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;
    string input;
    cin >> input;

    // intentional flooding
    for(int i=0; i<1000; i++){
        cout << "9";
        usleep(1000);
    }

    // indicate change of pov
    cout << endl;
    sleep(2);    
    cout << ". . ." << endl;
    sleep(2);
    cout << ". ." << endl;
    sleep(2);
    cout << "." << endl;
    sleep(2);

    // narrative from Asher's pov
    cout << "Cold." << endl;
    sleep(1);
    cout << "You woke up. Cold." << endl;
    sleep(1);
    cout << "You are surrounded by darkness. Cold." << endl;
    sleep(1);
    cout << "You shuffle around, desperately finding warmth and light." << endl;
    sleep(1);
    cout << "As you walk around, you stepped on something small. Something...cubic." << endl;
    cout << "You picked up the item, rubbing your sore foot.\nEngravings of dots. This must be the dice that Hestia keeps fidgeting." << endl;

    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;
    roll_dice(0);

    cout << "\nYou look around. \"Hest?\", you shout." << endl;
    sleep(2);
    cout << "No response.\n\"Hestia!\" you scream out her name." << endl;
    cout << "\nReturning your devastating call is a burst of red flames at the door." << endl;
    cout << "You rush to the flames, reaching out your hand to the warmth--" << endl;
    sleep(1);
    cout << "Flames touch the tips of your fingers.\nIt feels fuzzy and nostalgic, feels like hearth and hestia";
    sleep(1);
    cout << "The fire slowly spread to palms, crawing up your arms, scorching your body.\nIt getting too hot. You can feel  Hestia\'s fury." << endl;
    sleep(1);
    cout << "Before long, you are completelt engulfed in flames.\nYou can clearly feel Hestia\'s wrath through the burning pain on your skin." << endl;
    sleep(1);
    cout << "Hestia, standing at door. \nHer amber eyes reflecting the flickering flames, his pathetic begging figure being the centrepiece." << endl;
    cout << "She smiles and leaves, the door closing behind her, closing the fate of the man who betrayed her." << endl;
    
    sleep(2);    
    cout << ". . ." << endl;
    sleep(2);

    cout << "Ashes fills the air, spiralling lavishly under the dawning sun. \nFlames furiously flickering, dancing atrociously until the forest regained its silence." << endl;

    sleep(2);    
    cout << "The end." << endl;
    sleep(2);

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

// for debugging
int main(){
    ending1();
}