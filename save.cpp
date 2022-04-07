#include <iostream>
#include <fstream>
using namespace std;
#include "map.h"

void saveGame(Position player){
    ofstream fout;
    fout.open("savedata.txt");

    if(fout.fail()){
        cout << "file failed to open" << endl;
        exit(1);
    }

    fout << player.roomnum <<endl << player.x << endl << player.y;
    fout.close();

}

void loadGame(ifstream& fin, Position &player){
    fin >> player.roomnum >> player.x >> player.y;
}

int main(){
    Position player;
    player.roomnum = 1;
    player.x = 1;
    player.y = 1;
    saveGame(player);


    player.roomnum = 0;
    player.x = 0;
    player.y = 0;

    ifstream fin;
    fin.open("savedata.txt");
    int data[3];

    string input;

    cin >> input;
    if(input == "load"){
        loadGame(fin, player);
    }
    cout << player.roomnum << " " << player.x << " " << player.y;
}

