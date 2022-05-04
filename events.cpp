#include <iostream>
#include <string>
#include "roll.h"
#include "events.h"
#include "inventory.h"
#include "map.h"
using namespace std;

// int checkEventLocation(Position player){
//     if(player.roomnum == 1 && player.x == 3 && player.y == 4){
//         return 1;
//     }else if(player.roomnum == 2 && player.x == 4 && player.y == 2){
//         return 2;
//     }else if(player.roomnum == 2 && player.x == 2 && player.y == 6){
//         return 6;
//     }else if(player.roomnum == 3 && player.x == 3 && player.y == 4){
//         return 3;
//     }else if(player.roomnum == 3 && player.x == 7 && player.y == 4){
//         return 4;
//     }else if(player.roomnum == 4 && player.x == 6 && player.y == 2){
//         return 5;
//     }else if(player.roomnum == 4 && player.x == 6 && player.y == 3){
//         return 7;
//     }
//     else{
//         return 0;
//     }
// }

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

bool event2(bool haveFirewood){
    bool success(0);
    cout << "You see a fireplace in front of you. Wind blows into the room. Brrrrrrr it\'s chilly here." << endl;
    if(haveFirewood = false){            // have to pass event6 to continue -> check if they have firewood
        cout << "Although you want to light a fire, the absence of firewood prevents you from doing so" << endl;
        return false;
    }
    else if(haveFirewood == true){
        cout << "You light the fire with the firewood you found early. It warms your heart." << endl;
        cout << "But strangely, Asher seems scared. Not only fear on his face, you sense a slight hatred towards the fire from him." << endl;;
        return false;
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

bool event4(){
    cout << "In front of you is a small couch. The exhaustion from the trip finally hits you. \nYou\'ve decided to rest awhile on the couch." << endl;
    cout << "Roll a dice to determine your action (>=3) (type dice to roll)" << endl;

    if(roll_dice(1)){               // dice rolling >= 3
        cout << "You feel something under the cushions. Isn\'t it the Kit chocolate that Ashler always love?\nSuch a taste of a child.\n You wonder if the last traveller here has the same unique taste like him. "<<endl;
        return true;
    }else{
        cout << "Tiredness fills you up. You took a short nap on the couch."<< endl;
        return false;
    }
}

bool event5(Inventory inventory){
    cout << "Your attention is drawn to a vintage style treasure box. You try to open it but it is locked.\nA small keyhole can be vaguely seen on the side. \nWhere is the key?" << endl;
    if (inventory.key)
    {
        cout << "open the box with the key?(Y/N)" << endl;
        string input;
        cin >> input;
        while(1){
            if(input == "y" || input == "Y"){
                cout << "Inside contains a diary. It seems to be about a girl and her best friend. \nIt seems like an ordinary diary.  What concerns you most is that the last pages of the book is burned and written \n“Help”." << endl;
                return true;
            }
            else if(input == "n" || input == "N"){
                return false;
            }else{
                cout << "invalid input" << endl;
            }
        }

    }
}

bool event6(Inventory &inventory){
    string input;

    while(1){
        cout << "You found a firewood laying on the ground. Pick it up? (Y/N)" << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "pickup" << endl;
            // pick up
            // missing codes
            inventory.key = 1;
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

bool event7(Inventory &inventory){
    string input;

    while(1){
        cout << "You found a old rusted key. Pick it up? (Y/N)" << endl;
        cin >> input;
        if(input == "Y" || input == "y"){
            cout << "pickup" << endl;
            // pick up
            // missing codes
            inventory.key = 1;
            return true;
        }else if(input == "N" || input == "n"){
            //leave it
            cout << "You left the key where it was found." << endl;
            return false;
        }else{
            cout << "invalid input" << endl;
        }
    }
}

