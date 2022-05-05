#include <iostream>
#include <string>
#include <vector>
#include "events.h"
#include "inventory.h"
#include "map.h"
#include "roll.h"
using namespace std;

bool event1(EventProgress eventProgress){
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
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event2(vector <Inventory> inventory, EventProgress eventProgress){
    bool success(0);
    cout << "You see a fireplace in front of you. Wind blows into the room. Brrrrrrr it\'s chilly here." << endl;

    // have to pass event6 to continue
    // check for "firewood" in inventory
    bool flag=false;
    vector <Inventory>::iterator itr;
    for(itr=inventory.begin(); itr!=inventory.end(); itr++){
        if(itr->item == "firewood"){
            flag = true;
            break;
        }
    }
    if(flag){            
        cout << "Light up the fire with firewood? (Y/N)" << endl;
        string input;
        
        while(1){
            cin >> input;
            if(input == "y" || input == "Y"){
                cout << "You light the fire with the firewood you found earlier. It warms your heart." << endl;
                cout << "But strangely, Asher seems scared. Not only fear on his face, you sense a slight hatred towards the fire from him." << endl;;
                return true;
            }
            else if(input == "n" || input == "N"){
                cout << "Somehow you just don\'t want to start a fire." << endl;
                return false;
            }else{
                cout << "Invalid input" << endl;
            }
        }
    }
    return false;
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event3(EventProgress eventProgress){
    bool success(0);
    cout << "You spot an empty knife holder in a distance. There is a piece of paper above it, titled \"Instructions to...\"" <<endl;  
    cout << "However, it\'s too far away and you couldn\'t make out the rest of the sentence. " << endl;

    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;

    if(roll_dice(1)){               // dice rolling >= 3
        cout << "\nYou\'ve decided to walk closer to see what it is. You walk closer to the paper. The title is \"Instructions to forbid superpowers\" " << endl;
        cout << "\"1. Lead him/her to somewhere no one knows.\"\n2. Lead him/her to the roof.\"\n\"3. Use a knife to...\"" << endl;
        cout << "Asher grabs your hand and pulls you away. He seems terrified." << endl;
        cout << "\"Did you see anything?\" He speaks, his hand trembling.\n" << endl;
        return true;
    }else{
        cout << "\nYou\'ve decided to walk closer to see what it is. As you walked towards the paper, Asher grabbed your hand."<< endl;
        cout << "\"There is nothing to see, let\'s go.\"\n" << endl;
        return false;
    }
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event4(EventProgress eventProgress){
    cout << "In front of you is a small couch. The exhaustion from the trip finally hits you. \nYou\'ve decided to rest awhile on the couch." << endl;
    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;

    if(roll_dice(1)){               // dice rolling >= 3
        cout << "You feel something under the cushions. Isn\'t it the Kit chocolate that Ashler always love?\nSuch a taste of a child.\nYou wonder if the last traveller here has the same unique taste like him.\n"<<endl;
        return true;
    }else{
        cout << "Tiredness fills you up. You took a short nap on the couch.\n"<< endl;
        return false;
    }
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event5(vector <Inventory> inventory, EventProgress eventProgress){
    cout << "Your attention is drawn to a vintage style treasure box. You try to open it but it is locked.\nA small keyhole can be vaguely seen on the side. \nWhere is the key?" << endl;
    
    // have to pass event7 to continue
    // check for "key" in inventory
    bool flag=false;
    vector <Inventory>::iterator itr;
    for(itr=inventory.begin(); itr!=inventory.end(); itr++){
        if(itr->item == "key"){
            flag = true;
            break;
        }
    }   
    if(flag)
    {
        cout << "Open the box with the key? (Y/N) " << endl;
        string input;
        cin >> input;
        while(1){
            if(input == "y" || input == "Y"){
                cout << "Inside contains a diary. It seems to be about a girl and her best friend. \nIt seems like an ordinary diary.  What bothers you most is that the last pages of the book is burned and written \n\"Help\".\n" << endl;
                return true;
            }
            else if(input == "n" || input == "N"){
                cout << "Curiosity kills the cat. You are already tresspassing, now you want to be a stalker?\n" << endl;
                return false;
            }else{
                cout << "Invalid input." << endl;
            }
        }

    }
    return false;
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event6(vector <Inventory> &inventory, EventProgress eventProgress){
    string input;
    Inventory i;

    eventProgress.events++;
    while(1){
        cout << "You found a firewood laying on the ground. Pick it up? (Y/N) " << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "You picked up the piece of firewood.\n" << endl;
            // add item "firewood" to inventory
            i.item = "firewood";
            i.number = 1;
            inventory.push_back(i);
            cout << "Item added to inventory." << endl;
            return true;
        }else if(input == "N" || input == "n"){
            //leave the item
            cout << "You left the firewood where it was found.\n" << endl;
            return false;
        }else{
            cout << "Invalid input." << endl;
        }
    }
    return false;
    eventProgress.events++;         // to keep track of the number of events completed
}

bool event7(vector <Inventory> &inventory, EventProgress eventProgress){
    string input;
    Inventory i;

    while(1){
        cout << "You found a old rusted key. Pick it up? (Y/N) " << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "You picked up the key and placed it in your pockets.\n" << endl;
            // add item "key" to inventory
            i.item = "key";
            i.number = 1;
            inventory.push_back(i);
            cout << "Item added to inventory." << endl;
            return true;
        }else if(input == "N" || input == "n"){
            //leave the item
            cout << "You left the key where it was found.\n" << endl;
            return false;
        }else{
            cout << "Invalid input." << endl;
        }
    }
    return false;
    eventProgress.events++;         // to keep track of the number of events completed
}

