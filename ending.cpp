#include <iostream>
#include <unistd.h>
#include <chrono>
#include <fstream>
#include "events.h"
#include "roll.h"
#include "scenes.h"
using namespace std;

void Certificate(EventProgress eventProgress);


void ending1(EventProgress eventprogress){     // Good ending
    // evidence, print if each event is passed
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
    for(int i=0; i<5000; i++){
        cout << "9";
        usleep(5000);
    }

    // indicate change of pov
    cout << endl;
    sleep(3);    
    cout << ". . ." << endl;
    sleep(3);
    cout << ". ." << endl;
    sleep(3);
    cout << "." << endl;
    sleep(3);

    // narrative from Asher's pov
    cout << "Cold." << endl;
    sleep(2);
    cout << "You woke up. Cold." << endl;
    sleep(2);
    cout << "You are surrounded by darkness. Cold." << endl;
    sleep(2);
    cout << "You shuffle around, desperately finding warmth and light." << endl;
    sleep(1);
    cout << "As you walk around, you stepped on something small. Something...cubic." << endl;
    cout << "You picked up the item, rubbing your sore foot.\nEngravings of dots. This must be the dice that Hestia keeps fidgeting." << endl;

    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;
    
    // roll_dice(0) always returns true
    if(roll_dice(0)){
        cout << "\nYou look around. \"Hest?\", you shout." << endl;
        sleep(2);
        cout << "No response.\n\"Hestia!\" you scream out her name." << endl;
        cout << "\nReturning your devastating call is a burst of red flames at the door." << endl;
        cout << "You rush to the flames, reaching out your hand to the warmth--" << endl;
        sleep(2);
        cout << "Flames touch the tips of your fingers.\nIt feels fuzzy and nostalgic, feels like hearth and hestia";
        sleep(2);
        cout << "The fire slowly spread to palms, crawing up your arms, scorching your body.\nIt getting too hot. You can feel Hestia\'s fury." << endl;
        sleep(2);
        cout << "Before long, you are completelt engulfed in flames.\nYou can clearly feel Hestia\'s wrath through the burning pain on your skin." << endl;
        sleep(2);
        cout << "Hestia, standing at door. \nHer amber eyes reflecting the flickering flames, his pathetic begging figure being the centrepiece." << endl;
        cout << "She smiles and leaves, the door closing behind her, closing the fate of the man who betrayed her." << endl;
        
        sleep(2);    
        cout << ". . ." << endl;
        sleep(2);

        cout << "Ashes fills the air, spiralling lavishly under the dawning sun. \nFlames furiously flickering, dancing atrociously until the forest regained its silence." << endl;

        sleep(2);    
        cout << "The end." << endl;
        sleep(2);
        Certificate(eventprogress);
        exit(1);
    }
}

void ending2(){     // Bad ending
    cout << "Do you think it is just a game?" << endl;
    cout << "Why did you skip all the \"!\" even you had noticed them..." << endl;
    sleep(2); 
    cout << "You know, Hestia is also a person. Lend a helping hand!"<< endl;
    sleep(2); 
    cout << "YOU CAN SAVE HER!" << endl;
    exit(1);
}

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

    // the ending is dependent on the number of successful events   
    if(progress >= 3){                     
        ending1(eventprogress);
    }
    else{
        ending2();
    }
}

void Certificate(EventProgress eventProgress){
    ofstream fout;
    fout.open("_CERTIFICATE.txt");
    if ( fout.fail() ) {
      cout << "Error"<< endl;
      exit(1);
    }
    cout << "Thankyou for playing, please check out your certificate in \"_CERTIFICATE.txt\" file" << endl;
    fout << "            \\\\             =o)   " << endl;
    fout << "            (o>             /\\\\   " << endl;
    fout << "           _(()_CERTIFICATE_\\_V_ " << endl;
    fout << "            //               \\\\   " << endl;
    fout << "                              \\\\  " << endl;
    fout << "  __________________________________________  " << endl ;
    fout << "((           THANK YOU FOR PLAYING          ))" << endl;
    fout << " ))                                        (( " << endl;
    fout << "((        You have finished " << "5" << " events        ))" << endl;
    fout << " ))                                        ((" << endl;
    if(eventProgress.event1){
        fout << "((              The Newspaper               ))" << endl;
    }else{
        fout << "((                                          ))  " <<endl;
    }
    if(eventProgress.event2){
        fout << " ))             The Fireplace              ((" << endl;
    }else{
        fout << " ))                                        ((" << endl;
    }
    if(eventProgress.event3){
        fout << "(( The Empty Knife Holder and Instructions  ))" << endl;
    }else{
        fout << "((                                          )) " <<endl;
    }
    if(eventProgress.event4){
        fout << " ))           The Kit cholocate            (("  <<endl;
    }else{
        fout << " ))                                        ((" <<endl;
    }
    if(eventProgress.event5){
        fout << "((                 The Diary                ))" <<endl;
    }else{
        fout << "((                                          ))" <<endl;
    }
    fout << " ))                                        ((" << endl;
    fout << "((              and SAVE HESTIA             ))" <<endl;
    fout << " ))                                        ((  " <<endl;
    fout << "((                         game presented by))" <<endl;
    fout << " ))                         Grace and Jacky((" << endl;
    fout << "  ------------------------------------------"  <<endl;

}