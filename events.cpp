#include <iostream>
#include <string>
#include "roll.h"
#include "events.h"
using namespace std;

bool event1(){
    bool success(0);
    cout << "You found a piece of paper laying on the floor.\nIt is an old black and white newspaper clipping bearing the heading\n";
    cout << "\033[1;31m\"Miracle! The Only Survivor In the Burning House\"\033[0m\n";
    cout << "There is a photo of a girl covered in flames yet standing straight, glaring straight at the camera." << endl;
    cout << "Oddly enough, you feel a connection with the house and those pair of amber eyes. " << endl;
    cout << endl;
    cout << "You are curious why is it here.\n" << endl;

    cout << "roll a dice to determine your action (>=3) (type dice to roll)" << endl;

    if(roll_dice(1)){               // dice rolling >= 3
        cout << "\nYou\'ve decided to ask Asher if he knows anything." << endl;
        cout << "Carefully putting the newspaper in your pocket, you muster up the courage to ask Asher about this news." << endl;
        cout << "He shakes his head vigorously and urge me to move on.\nIt\'s odd how he reacted.\n" << endl;
        return true;
    }else{
        cout << "\nMaybe it\'s just a simple coincidence." << endl;
        cout << "How could Asher possibly know our car would break down in the middle of nowhere, and that there is such a house beforehand?" << endl;
        cout << "There should be nothing to worry about.\n" << endl;
        return false;
    }
}

bool event2(){
    bool success(0);
    cout << "You see a fireplace in front of you. Wind blows into the room. Brrrrrrr it’s chilly here." << endl;
    if(event6 == false){            // have to pass event6 to continue
        cout << "Although you want to light a fire, the absence of firewood prevents you from doing so" << endl;
    }
    else{
        cout << "You stretch out your hand, trying to generate some fire." << endl;

        cout << "roll a dice to determine your action (>=3) (type dice to roll)" << endl;

        if(roll_dice(1)){           // dice rolling >= 3
            cout << "\nYou\'ve successfully used your fire ability. Even you were shocked by the fire.\nHowever, Asher seems scared." << endl;
            cout << "He screamed.Not only fear on his face, you sense a slight hatred towards your ability from him." << endl;
            return true;
        }else{
            cout << "\nYou can\'t use your fire ability. Asher looks at you and smile in a strange way." << endl;
            cout << "It looks like he is…relieved?" << endl;
            return false;
        }
    }
}

bool event3(){
    bool success(0);
    cout << "You spot an empty knife holder in a distance. There is a piece of paper above it, titled “Instructions to…”" <<endl;  
    cout << "However, it\'s too far away and you couldn\'t make out the rest of the sentence. " << endl;

    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;

    if(roll_dice(1)){               // dice rolling >= 3
        cout << "\nYou\'ve decided to walk closer to see what it is. You walk closer to the paper. The title is \"Instructions to forbid superpowers\" " << endl;
        cout << "“1. Lead him/her to somewhere no one knows.”\n“2. Lead him/her to the roof.”\n“3. Use a knife to…”" << endl;
        cout << "Asher grabs your hand and pulls you away. He seems terrified." << endl;
        cout << "“Did you see anything?” He speaks, his hand trembling." << endl;
        return true;
    }else{
        cout << "\nYou\'ve decided to walk closer to see what it is. As you walked towards the paper, Asher grabbed your hand."<< endl;
        cout << "“There is nothing to see, let\'s go.”" << endl;
        return false;
    }
}

bool event6(){
    string input;

    while(1){
        cout << "You found a firewood laying on the ground. Pick it up? (Y/N)" << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "pickup" << endl;
            // pick up
            // missing codes
            return true;
        }else if(input == "N" || input == "n"){
            //leave it
            cout << "You left the firewood where it was found." << endl;
            return false;
        }else{
            cout << "invalid input" << endl;
        }
    }
}

bool event7(){
    string input;

    while(1){
        cout << "You found a old rusted key. Pick it up? (Y/N)" << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "pickup" << endl;
            // pick up
            // missing codes
            break;
        }else if(input == "N" || input == "n"){
            //leave it
            cout << "You left the key where it was found." << endl;
            return false;
        }else{
            cout << "invalid input" << endl;
        }
    }
}

