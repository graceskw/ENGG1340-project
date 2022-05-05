#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "commands.h"
#include "events.h"	
#include "inventory.h"
#include "map.h"
#include "scenes.h"
using namespace std;

void checkEventLocation(Position player, vector <Inventory> &inventory, EventProgress &eventProgress);

int main()
{	
	vector<vector<char>> map(10,vector<char>(10));
	SceneChange sceneChange;
	Position player;
	EventProgress eventProgress;
	vector <Inventory> inventory;
	// initialse the player's position
	player.x = 4;
	player.y = 7;
	player.roomnum = 0;
	// initialise event status to false 
	eventProgress.event1 = eventProgress.event2 = eventProgress.event3 = eventProgress.event4 = eventProgress.event5 = eventProgress.event6 = eventProgress.event7 = 0;
	
	// add item "Dice" to inventory
	Inventory i;
	i.item = "Dice";
	i.number = 1;
	inventory.push_back(i);

	// generate map for current scene
	generatemap(player, map, eventProgress);

	// play beginning scene
	beginning(player, map, sceneChange);
	
	while(1){
		// check the location for each event in each scene
		checkEventLocation(player, inventory, eventProgress);
		// generate map for current scene
		generatemap(player,map,eventProgress);
		// output map
		Printmap(player, map);
		cout << "-----------------------------------" << endl;
		// player input 
		commands(player, map, sceneChange, inventory, eventProgress);
		cout << "-----------------------------------" << endl;
	}
}

// check the location for each event in each scene
void checkEventLocation(Position player, vector <Inventory> &inventory, EventProgress &eventProgress){
    if(player.roomnum == 1 && player.x == 3 && player.y == 4 && !eventProgress.event1){		// for debugging
        eventProgress.event1 = event1(eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 2 && player.x == 4 && player.y == 2 && !eventProgress.event6){
        eventProgress.event6 = event6(inventory, eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 2 && player.x == 2 && player.y == 6 && !eventProgress.event2){
    	eventProgress.event2 = event2(inventory, eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 3 && player.x == 3 && player.y == 4 && !eventProgress.event3){
        eventProgress.event3 = event3(eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 3 && player.x == 7 && player.y == 4 && !eventProgress.event4){
        eventProgress.event4 = event4(eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 4 && player.x == 6 && player.y == 2 && !eventProgress.event5){
        eventProgress.event5 = event5(inventory, eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 4 && player.x == 6 && player.y == 3 && !eventProgress.event7){
        eventProgress.event7 = event7(inventory, eventProgress);
		cout << "-----------------------------------" << endl;
    }
	else if(player.roomnum == 5){
		final(eventProgress);
	}
}