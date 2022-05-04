#include <iostream>
#include <fstream>
#include <vector>
#include "map.h"
#include "inventory.h"
#include "events.h"
using namespace std;

void saveGame(Position player, vector <Inventory> inventory, EventProgress eventProgress){
    ofstream fout;
    fout.open("savedata_map.txt");

    if(fout.fail()){
        cout << "file failed to open" << endl;
        exit(1);
    }

    fout << player.roomnum <<endl << player.x << endl << player.y;
    fout.close();
    

    //inventory part:
    fout.open("savedata_inventory.txt");
    if(fout.fail()){
        cout << "file failed to open" << endl;
        exit(1);
    }

    vector <Inventory>::iterator itr;
    for(itr=inventory.begin(); itr!=inventory.end(); itr++){
        fout << itr->item << endl;
    }
    fout.close();

    //events part:
    fout.open("savedata_event.txt");
    if(fout.fail()){
        cout << "file failed to open" << endl;
        exit(1);
    }

    fout << eventProgress.event1 << endl << eventProgress.event2 << endl << eventProgress.event3 << endl << eventProgress.event4 << endl << eventProgress.event5 << endl << eventProgress.event6 << endl << eventProgress.event7 << endl;
    fout.close() ;


}

void loadGame(Position &player, vector <Inventory> inventory, EventProgress eventProgress){
    ifstream fin;
    fin.open("savedata_map.txt");

    fin >> player.roomnum >> player.x  >> player.y ;
    fin.close();

    //repeat for inventory and events
    fin.open("savedata_inventory.txt");
    vector <Inventory>::iterator itr;
    for(itr=inventory.begin(); itr!=inventory.end(); itr++){
        fin >> itr->item >> itr->number;
    }
    fin.close();
        
        
    fin.open("savedata_event.txt");

    fin >> eventProgress.event1 >> eventProgress.event2 >> eventProgress.event3 >> eventProgress.event4 >> eventProgress.event5 >> eventProgress.event6 >> eventProgress.event7;
    fin.close();


}


//only for testing
int main(){
    Position player;
    vector <Inventory> inventory;
    EventProgress eventProgress;
    player.roomnum = 1;
    player.x = 1;
    player.y = 1;
    saveGame(player, inventory, eventProgress);


    player.roomnum = 0;
    player.x = 0;
    player.y = 0;

    ifstream fin;
    fin.open("savedata.txt");
    int data[3];

    string input;

    cin >> input;
    if(input == "load"){
        //loadGame(player, inventory, eventProgress);
    }
    cout << player.roomnum << " " << player.x << " " << player.y;
}

