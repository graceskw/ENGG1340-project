// implement commands, ending 
// figure how to link everything up

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "map.h"
#include "inventory.h"
#include "scenes.h"
#include "events.h"	//see if you want to make a .h file to contain all .h, all fine for me
using namespace std;

int main()
{
	vector<vector<char>> map(10,vector<char>(10));
	SceneChange sceneChange;
	Position player;
	EventProgress eventProgress;
	Inventory* inventory = new Inventory;		//dynamic memory
	player.x = 4;
	player.y = 6;
	player.roomnum = 0;
	
	generatemap(player, map);	//here 1,1,1,1 refers to 4 rand no for room 1,2,3,4

	Printmap(player,map);

	beginning();
	
	while(1){
		cout << "input : "<< endl;
		string input;
		cin >> input;
		
		//do command!
		//change the belows all to command "map" is ok
		cout << player.x << player.y << endl;
		player = Movement(input, player, map, sceneChange);	
		if(sceneChange.change){
			cout << "changescene" << endl;
			checkScene(player, sceneChange);
			generatemap(player, map);
		}
		Printmap(player, map);
	}



	delete inventory;

	//when use event funcitons: eventProgress.event1 = event1();, event2(inventory.firewood), event3(), event4(), event5(inventory), event6(inventory), event7(inventory);
}