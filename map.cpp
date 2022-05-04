#include <iostream>
#include <vector>
#include "map.h"
#include "events.h"

using namespace std;

/* template map
				map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
*/
void generatemap (Position &player, vector<vector<char>> &map, EventProgress eventProgress){
	switch(player.roomnum){
		case 0: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ','+',' ',' ',' ',' ',' '},
				{' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				{' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				{' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				{' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				{' ',' ',' ','|','=','|',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//start:[7][4], rm1->rm0: [2][4]
			break;
		case 1: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ','_','_','_','_','_','+','_','_',' '},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'+',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|','_','_','_','=','_','_','_','_','|'},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//rm0->rm1: [7][4], rm2->rm1: [5][0], rm3->rm1: [2][6]

				// map = {										//if seed == 2 for rm1
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ','_','_','_','_','_','+','_','_',' '},
				// {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				// {'|',' ',' ',' ',' ','_','_','_','_',' '},
				// {'+',' ',' ',' ',' ','|',' ',' ',' ',' '},
				// {'|','_','_','_',' ','|',' ',' ',' ',' '},
				// {' ',' ',' ','|','=','|',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
				
				//event1_loc.x = 3, event1_loc.y = 4;     //if eventprogress.event1 == 0;
				if (eventProgress.event1 == 0){
					map[4][3] = '!';
				}
			break;
		case 2: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ','_','_','_','_','_','_',' ',' '},
				{' ','|',' ',' ',' ',' ',' ','+',' ',' '},
				{' ','|',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','|',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','|',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','|',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','|','_','_','_','_','_','|',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//rm1->rm2: [2][7]
				// map = {
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ','_','_','_','_',' ',' '},
				// {' ',' ',' ','|',' ',' ',' ','+',' ',' '},
				// {' ',' ',' ','|',' ',' ','_','_',' ',' '},
				// {' ',' ','_','|',' ',' ','|',' ',' ',' '},
				// {' ','|',' ',' ',' ',' ','|',' ',' ',' '},
				// {' ','|',' ',' ',' ',' ','|',' ',' ',' '},
				// {' ','|',' ',' ',' ',' ','|',' ',' ',' '},
				// {' ','|','_','_','_','_','|',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

				//event6_loc.x = 4, event6_loc.y = 2;
				//event2_loc.x = 2, event2_loc.y = 6;
				if(eventProgress.event2 == 0){
					map[6][2]='!';
				}
				if(eventProgress.event6 == 0){
					map[2][4] = '!';
				}

		case 3: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ','_','_','_','_','_','_',' ',' '},
				{' ','|',' ',' ',' ',' ',' ',' ','|',' '},
				{' ','|',' ',' ',' ',' ',' ',' ','+',' '},
				{' ','|',' ',' ',' ',' ',' ',' ','|',' '},
				{' ','|','_','_','+','_','_','_','|',' '},		//rm1->rm3: [7][4] rm4->rm3: [5][8]
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
				// map = {
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ','_','_','_','_','_',' ',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','+',' '},
				// {' ',' ','|',' ',' ',' ',' ','_','|',' '},
				// {' ',' ','|','_','+','_','_','|',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

				// event3_loc.x = 3, event3_loc.y = 4;
				// event4_loc.x = 7, event4_loc.y = 4;
				if(eventProgress.event3 == 0){
					map[4][3] = '!';
				}
				if(eventProgress.event4 == 0){
					map[4][7] = '!';
				}

		case 4: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ','_','_','_','_','_','_',' ',' ',' '},
				{' ','+',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','_','_','_','_',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|','+','_','|',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//rm3->rm4: [2][1],  rm5->rm4: [8][5]
				// map = {
				// {' ',' ','_','_','_','_','_','_','_',' '},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','+',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ',' ','_','_','_','+','_','_','_','|'},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

				// event5_loc.x = 6, event5_loc.y = 2;
				// event7_loc.x = 6, event7_loc.y = 3;
				if(eventProgress.event5==0){
					map[2][6] = '!';
				}
				if(eventProgress.event7==0){
					map[3][6] = '!';
				}
		case 5:map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ','_','_','|','+','|','_','_',' ',' '},
				{'|',' ',' ',' ',' ',' ',' ',' ','|',' '},
				{'|',' ',' ',' ',' ',' ',' ',' ','|',' '},
				{'|',' ',' ',' ',' ',' ',' ',' ','|',' '},
				{'|','_','_','_','_','_','_','_','|',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//rm4->rm5: [1][4]
	}
}



Position Movement(string input, Position player, vector<vector<char>> map, SceneChange &sceneChange){
	// string input;
	sceneChange.change = 0;
	// this part may merge with commands
	// cout << "WASD?";
	// cin >> input;
	// cout << endl;
	if((input == "w" || input == "W") && (map[player.y-1][player.x] != '|' && map[player.y-1][player.x] != '_')){
		player.y--;
	}else if((input == "s" || input == "S") && (map[player.y+1][player.x] != '|' && map[player.y+1][player.x] != '_')){
		player.y++;
	}else if((input == "a" || input == "A") && (map[player.y][player.x-1] != '|' && map[player.y][player.x-1] != '_')){
		player.x--;
	}else if((input == "d" || input == "D") && (map[player.y][player.x+1] != '|' && map[player.y][player.x+1] != '_')){
		player.x++;
	}else{
		cout << "invalid input" << endl;
	}

	if(map[player.y][player.x] == '+' || map[player.y][player.x] == '='){
		cout << "scenechange" << endl;
		sceneChange.change = 1;
		if((input == "w" || input == "W")){
			sceneChange.direction = 'w';
		}else if((input == "s" || input == "S")){
			sceneChange.direction = 's';
		}else if((input == "a" || input == "A")){
			sceneChange.direction = 'a';
		}else if((input == "d" || input == "D")){
			sceneChange.direction = 'd';
		}
	}
	return player;
}

void checkScene(Position &player, SceneChange sceneChange){
	switch(player.roomnum){
		case 0:
			switch(sceneChange.direction){
				case 'w':	
					player.roomnum = 1;
					player.x = 4;
					player.y = 6;
					break;
				case 's':
					player.roomnum = 0;
					player.x = 4;
					player.y = 6;
					cout << "there is no exit" << endl;
					break;
			}
		break;
		case 1:
			switch(sceneChange.direction){
				case 's':
					player.roomnum = 0;
					player.x = 4;
					player.y = 3;
					break;
			}
	}
}

void Printmap(Position player, vector<vector<char>> map){
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			if(i == player.y && j == player.x){
				cout << " " << 'X' ;
			}
			else{
				cout << " " << map[i][j];
			}
		}
		cout << endl;
	}
}
