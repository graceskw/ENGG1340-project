#include <iostream>
#include <vector>
#include "map.h"

using namespace std;


void generatemap (Position &player, vector<vector<char>> &map){
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
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
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
				{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
			break;
	}
}



Position Movement(Position player, vector<vector<char>> map, SceneChange &sceneChange){
	string input;
	sceneChange.change = 0;
	cout << "WASD?";
	cin >> input;
	cout << endl;
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
