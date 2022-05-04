// implement commands, ending 
// figure how to link everything up

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "map.h"
#include "inventory.h"
#include "scenes.h"
#include "commands.h"
#include "events.h"	//see if you want to make a .h file to contain all .h, all fine for me
#include "testing.h"
using namespace std;

int main()
{
	vector<vector<char>> map(10,vector<char>(10));
	SceneChange sceneChange;
	Position player;
	EventProgress progress;
	vector <Inventory> inventory;		//dynamic memory
	player.x = 4;
	player.y = 6;
	player.roomnum = 0;
	
	generatemap(player, map);	//here 1,1,1,1 refers to 4 rand no for room 1,2,3,4

	Printmap(player,map);

	beginning(player, map);
	
	while(1){
		commands(player, map, sceneChange, inventory);

		// cout << "input : "<< endl;
		// string input;
		// cin >> input;
		
		//do command!
		//change the belows all to command "map" is ok

		// merged with commands
		// cout << player.x << player.y << endl;
		// player = Movement(input, player, map, sceneChange);	
		// if(sceneChange.change){
		// 	cout << "changescene" << endl;
		// 	checkScene(player, sceneChange);
		// 	generatemap(player, map);
		// }
		// Printmap(player, map);
	}



	// delete inventory;

	//when use event funcitons: eventProgress.event1 = event1();, event2(inventory.firewood), event3(), event4(), event5(inventory), event6(inventory), event7(inventory);
}

int checkEventLocation(Position player, Inventory inventory){
    if(player.roomnum == 1 && player.x == 3 && player.y == 4){
        event1();
    }else if(player.roomnum == 2 && player.x == 4 && player.y == 2){
        event2(inventory);
    }else if(player.roomnum == 2 && player.x == 2 && player.y == 6){
        event6(inventory);
    }else if(player.roomnum == 3 && player.x == 3 && player.y == 4){
        event3();
    }else if(player.roomnum == 3 && player.x == 7 && player.y == 4){
        event4();
    }else if(player.roomnum == 4 && player.x == 6 && player.y == 2){
        event5(inventory);
    }else if(player.roomnum == 4 && player.x == 6 && player.y == 3){
        event7(inventory);
    }
    else{
        return 0;
    }
}