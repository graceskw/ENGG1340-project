// implement commands, ending<-room 5
// figure how to link everything up

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
	vector <Inventory> inventory;		//dynamic memory
	player.x = 4;
	player.y = 6;
	player.roomnum = 0;
	eventProgress.event1 = eventProgress.event2 = eventProgress.event3 = eventProgress.event4 = eventProgress.event5 = eventProgress.event6 = eventProgress.event7 = 0;
	
	Inventory i;
	i.item = "Dice";
	i.number = 1;
	inventory.push_back(i);

	generatemap(player, map, eventProgress);	//here 1,1,1,1 refers to 4 rand no for room 1,2,3,4

	// Printmap(player,map);

	beginning(player, map, sceneChange);
	

	// if room 5 then break?
	while(1){
		checkEventLocation(player, inventory, eventProgress);
		generatemap(player,map,eventProgress);
		Printmap(player, map);
		cout << "-----------------------------------" << endl;
		commands(player, map, sceneChange, inventory, eventProgress);
		cout << "-----------------------------------" << endl;
	}



	// delete inventory;


	//when use event funcitons: eventProgress.event1 = event1();, event2(inventory.firewood), event3(), event4(), event5(inventory), event6(inventory), event7(inventory);
}

void checkEventLocation(Position player, vector <Inventory> &inventory, EventProgress &eventProgress){
    // if(player.roomnum == 1 && player.x == 3 && player.y == 4){
    if(player.roomnum == 1 && player.x == 3 && player.y == 4 && !eventProgress.event1){		// for debugging
        eventProgress.event1 = event1(eventProgress);
    }
	else if(player.roomnum == 2 && player.x == 4 && player.y == 2 && !eventProgress.event6){
        eventProgress.event6 = event6(inventory, eventProgress);
    }
	else if(player.roomnum == 2 && player.x == 2 && player.y == 6 && !eventProgress.event2){
    	eventProgress.event2 = event2(inventory, eventProgress);
    }
	else if(player.roomnum == 3 && player.x == 3 && player.y == 4 && !eventProgress.event3){
        eventProgress.event3 = event3(eventProgress);
    }
	else if(player.roomnum == 3 && player.x == 7 && player.y == 4 && !eventProgress.event4){
        eventProgress.event4 = event4(eventProgress);
    }
	else if(player.roomnum == 4 && player.x == 6 && player.y == 2 && !eventProgress.event5){
        eventProgress.event5 = event5(inventory, eventProgress);
    }
	else if(player.roomnum == 4 && player.x == 6 && player.y == 3 && !eventProgress.event7){
        eventProgress.event7 = event7(inventory, eventProgress);
    }
}