#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "inventory.h"
#include "events.h"	
#include "events.cpp"
// #include "roll.h"
// #include "map.h"
// #include "scenes.h"
// #include "commands.h"
// #include "testing.h"

using namespace std;

int main(){
	Inventory *inventory = new Inventory;		//dynamic memory


    // event1();
    // event2(*inventory);     //in main.cpp: event2(inventory.firewood);
    // event3();
    // event4();
    event5(*inventory);

    // event6(*inventory);
    event7(*inventory);
    event5(*inventory);     //in main.cpp: event2(inventory.firewood);

}

