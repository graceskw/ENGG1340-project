//EVENT3 -- use firewood

#include <iostream>
using namespace std;

int main(){
    bool success(0);
    cout << "You see a fireplace with firewood in front of you. Wind blows into the room. Brrrrrrr it’s chilly here." << endl;
    cout << "You stretch out your hand, trying to generate some fire." << endl;

    cout << "Throw a dice to determine your action (>=3) (type dice)" << endl;

    // throw dice

    if(success){
        cout << "You\'ve successfully used your fire ability. Even you were shocked by the fire.\nHowever, Asher seems scared." << endl;
        cout << "He screamed.Not only fear on his face, you sense a slight hatred towards your ability from him." << endl;
    }else{
        cout << "You can\'t use your fire ability. Asher looks at you and smile in a strange way." << endl;
        cout << "It looks like he is…relieved?" << endl;
    }
}