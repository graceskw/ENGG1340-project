#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include "map.h"
using namespace std;

int main()
{
	vector<vector<char>> map(10,vector<char>(10));
	SceneChange sceneChange;
	Position player;
	player.x = 4;
	player.y = 6;
	player.roomnum = 0;
	
	generatemap(player, map);	//here 1,1,1,1 refers to 4 rand no for room 1,2,3,4

	Printmap(player,map);

	while(1){
		cout << player.x << player.y << endl;
		player = Movement(player, map, sceneChange);
		if(sceneChange.change){
			cout << "changescene" << endl;
			checkScene(player, sceneChange);
			generatemap(player, map);
		}
		Printmap(player, map);
	}
}