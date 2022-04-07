#include <iostream>
using namespace std;

int main(){
    bool success(0);
    cout << "You found a piece of paper laying on the floor.\nIt is an old black and white newspaper clipping bearing the heading\n";
    cout << "\033[1;31m\"Miracle! The Only Survivor In the Burning House\"\033[0m\n";
    cout << "There is a photo of a girl covered in flames yet standing straight, glaring straight at the camera." << endl;
    cout << "Oddly enough, you feel a connection with the house and those pair of amber eyes. " << endl;
    cout << endl;
    cout << "You are curious why is it here.\n" << endl;

    cout << "Throw a dice to determine your action (>=3) (type dice)" << endl;

    // throw dice

    if(success){
        cout << "You\'ve decided to ask Asher if he knows anything." << endl;
        cout << "Carefully putting the newspaper in your pocket, you muster up the courage to ask Asher about this news." << endl;
        cout << "He shakes his head vigorously and urge me to move on.\nIt\'s odd how he reacted.\n" << endl;
    }else{
        cout << "Maybe it\'s just a simple coincidence." << endl;
        cout << "How could Asher possibly know our car would break down in the middle of nowhere, and that there is such a house beforehand?" << endl;
        cout << "There should be nothing to worry about.\n" << endl;
    }


}