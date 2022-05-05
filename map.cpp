#include <iostream>
#include <vector>
#include "events.h"
#include "map.h"

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
				{' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				{' ',' ',' ',' ','=',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//start:[7][4], rm1->rm0: [2][4]
			break;
		case 1: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ','+',' ',' ',' '},
				{' ','_','_','_','_','_',' ','_','_',' '},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'+',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				{'|','_','_','_',' ','_','_','_','_','|'},
				{' ',' ',' ',' ','=',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};		//rm0->rm1: [7][4], rm2->rm1: [5][0], rm3->rm1: [2][6]

				// map = {										//if seed == 2 for rm1
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ','+',' ',' ',' '},
				// {' ','_','_','_','_','_',' ','_','_',' '},
				// {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				// {'|',' ',' ',' ',' ','_','_','_','_',' '},
				// {'+',' ',' ',' ',' ','|',' ',' ',' ',' '},
				// {'|','_','_','_',' ','|',' ',' ',' ',' '},
				// {' ',' ',' ','|',' ','|',' ',' ',' ',' '},
				// {' ',' ',' ',' ','=',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
				
				//event1_loc.x = 3, event1_loc.y = 4;     //if eventprogress.event1 == 0;
				if (eventProgress.event1 == 0){
					map[4][3] = '!';
				}
			break;
		case 2: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ','_','_','_','_','_','_',' ',' '},
				{' ','|',' ',' ',' ',' ',' ',' ','+',' '},
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
				// {' ',' ',' ','|',' ',' ',' ',' ','+',' '},
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
			break;
		case 3: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ',' ','_','_','_','_','_','_',' ',' '},
				{' ','|',' ',' ',' ',' ',' ',' ','|',' '},
				{' ','|',' ',' ',' ',' ',' ',' ',' ','+'},
				{' ','|',' ',' ',' ',' ',' ',' ','|',' '},
				{' ','|','_','_',' ','_','_','_','|',' '},		//rm1->rm3: [7][4] rm4->rm3: [5][8]
				{' ',' ',' ',' ','+',' ',' ',' ',' ',' '},
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
				// map = {
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				// {' ',' ',' ','_','_','_','_','_',' ',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ','|',' '},
				// {' ',' ','|',' ',' ',' ',' ',' ',' ','+'},
				// {' ',' ','|',' ',' ',' ',' ','_','|',' '},
				// {' ',' ','|','_',' ','_','_','|',' ',' '},
				// {' ',' ',' ',' ','+',' ',' ',' ',' ',' '},
				// {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

				// event3_loc.x = 3, event3_loc.y = 4;
				// event4_loc.x = 7, event4_loc.y = 4;
				if(eventProgress.event3 == 0){
					map[4][3] = '!';
				}
				if(eventProgress.event4 == 0){
					map[4][7] = '!';
				}
			break;
		case 4: map = {
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
				{' ','_','_','_','_','_','_',' ',' ',' '},
				{'+',' ',' ',' ',' ',' ',' ','|',' ',' '},
				{' ','_','_','_','_',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ',' ','|',' ',' '},
				{' ',' ',' ',' ','|',' ','_','|',' ',' '},
				{' ',' ',' ',' ',' ','+',' ',' ',' ',' '}};		//rm3->rm4: [2][1],  rm5->rm4: [8][5]
				// map = {
				// {' ',' ','_','_','_','_','_','_','_',' '},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {'+',' ',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
				// {' ',' ','_','_','_',' ','_','_','_','|'},
				// {' ',' ',' ',' ',' ','+',' ',' ',' ',' '}};

				// event5_loc.x = 6, event5_loc.y = 2;
				// event7_loc.x = 6, event7_loc.y = 3;
				if(eventProgress.event5==0){
					map[2][6] = '!';
				}
				if(eventProgress.event7==0){
					map[3][6] = '!';
				}
			break;
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
			break;
	}
}



Position Movement(string input, Position player, vector<vector<char>> map, SceneChange &sceneChange){
	cout << "player -x, y:" << player.x << player.y << player.roomnum << endl;
	sceneChange.change = 0;
	string dir_w="wW", dir_a="aA", dir_s="sS", dir_d="dD";

	if((dir_w.find(input)!=std::string::npos) && (map[player.y-1][player.x] != '|' && map[player.y-1][player.x] != '_')){
		player.y--;
	}
	else if((dir_s.find(input)!=std::string::npos) && (map[player.y+1][player.x] != '|' && map[player.y+1][player.x] != '_')){
		player.y++;
	}
	else if((dir_a.find(input)!=std::string::npos) && (map[player.y][player.x-1] != '|' && map[player.y][player.x-1] != '_')){
		player.x--;
	}
	else if((dir_d.find(input)!=std::string::npos) && (map[player.y][player.x+1] != '|' && map[player.y][player.x+1] != '_')){
		player.x++;
	}
	cout << "player -x, y:" << player.x << player.y << player.roomnum << endl;

	if(map[player.y][player.x] == '+' || map[player.y][player.x] == '='){
		cout << "scenechange" << endl;
		sceneChange.change = 1;
		if(dir_w.find(input)!=std::string::npos){
			sceneChange.direction = 'w';
		}else if(dir_s.find(input)!=std::string::npos){
			sceneChange.direction = 's';
		}else if(dir_a.find(input)!=std::string::npos){
			sceneChange.direction = 'a';
		}else if(dir_d.find(input)!=std::string::npos){
			sceneChange.direction = 'd';
		}
	}
	return player;
}

void checkScene(Position &player, SceneChange sceneChange){
	cout << player.roomnum << player.x << player.y << endl;
	cout << "-----scenechange---" << endl; 
	switch(player.roomnum){
		case 0:
			switch(sceneChange.direction){
				case 'w':	
					player.roomnum = 1;
					player.x = 4;
					player.y = 7;
					break;
				case 's':
					player.roomnum = 0;
					player.x = 4;
					player.y = 7;
					cout << "\"TRUST ME, Hestia\"";
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
				case 'a':
					player.roomnum = 2;
					player.x = 7;
					player.y = 2;
					break;
				case 'w':
					player.roomnum = 3;
					player.x = 4;
					player.y = 7;
					break;
			}
		break;
		case 2:
			switch(sceneChange.direction){
				case 'd':
					player.roomnum = 1;
					player.x = 1;
					player.y = 5;
					break;
			}
		break;
		case 3:
			switch(sceneChange.direction){
				case 's':
					player.roomnum = 1;
					player.x = 6;
					player.y = 2;
					break;
				case 'd':
					player.roomnum = 4;
					player.x = 1;
					player.y = 2;
					break;
			}
		break;
		case 4:
			switch(sceneChange.direction){
				case 'a':
					player.roomnum = 3;
					player.x = 8;
					player.y = 5;
					break;
				//case s: ending!!!!?
			}
		break;
	}
	cout << player.roomnum << player.x << player.y << endl;
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
