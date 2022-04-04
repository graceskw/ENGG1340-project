#include <iostream>
#include <iomanip>
using namespace std;

struct Position{
	int roomnum;
	int x;
	int y;
};


char generatemap (char rm0map[][3], int rm1num, int rm2num, char rm1map[][9], char rm2map[][8]){
	char temp[6][3] = {
		{' ','+',' '},
		{'|',' ','|'},
		{'|',' ','|'},
		{'|',' ','|'},
		{'|',' ','|'},
		{'|','=','|'}};
	switch(rm1num){
		case 1:
		rm1map = new char[6][9]{
		{' ','_','_','_','_','_','_','+',' '},
		{'|',' ',' ',' ','!',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ','|'},
		{'+',' ',' ',' ',' ',' ',' ','!','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|','_','_','_','=','_','_','_','|'}};
	}
	memcpy((&rm0map), temp, sizeof(rm0map));
	
}

Position Movement(Position player, char map[][3]){
	string input;
	cin >> input;
	if(input == "w" || input == "W"){
		player.x--;
	}
	return player;
}

void Printmap(Position player, char map[][3]){
	for(int i = 0; i<6; i++){
		for(int j = 0; j<3; j++){
			cout << " " << map[i][j];
		}
		cout << endl;
	}
}

int main()
{
	char rm0map[6][3], rm1map[6][9], rm2map[4][8];

	for(int i = 0; i<6; i++){
		for(int j = 0; j<3; j++){
			cout << " " << rm0map[i][j];
		}
		cout << endl;
	}
	cout << "-------------------" << sizeof(rm0map) << endl;
	int randrm1(1), randrm2(1);				//random number fro rm1 and 2
	
	generatemap(rm0map, randrm1, randrm2, rm1map, rm2map); 	//here 1,1,1,1 refers to 4 rand no for room 1,2,3,4

	for(int i = 0; i<6; i++){
		for(int j = 0; j<3; j++){
			cout << " " << rm0map[i][j];
		}
		cout << endl;
	}

	Position player;
	player.roomnum = 0;
	player.x = 4;
	player.y = 1;

	while(1){
		switch(player.roomnum){
			case 0:
			Movement(player, rm0map);
		}
	}
}