//EVENT4 

#include <iostream>
using namespace std;

int main(){
    bool success(0);
    cout << "You spot an empty knife holder in a distance. There is a piece of paper above it, titled “Instructions to…”" <<endl;  
    cout << "However, it\'s too far away and you couldn\'t make out the rest of the sentence. " << endl;

    cout << "Throw a dice to determine your action (>=3) (type dice)" << endl;

    // throw dice

    if(success){
        cout << "You\'ve decided to walk closer to see what it is. You walk closer to the paper. The title is \"Instructions to forbid superpowers\" " << endl;
        cout << "“1. Lead him/her to somewhere no one knows.”\n“2. Lead him/her to the roof.”\n“3. Use a knife to…”" << endl;
        cout << "Asher grabs your hand and pulls you away. He seems terrified." << endl;
        cout << "“Did you see anything?” He speaks, his hand trembling." << endl;
    }else{
        cout << "You\'ve decided to walk closer to see what it is. As you walked towards the paper, Asher grabbed your hand."<< endl;
        cout << "“There is nothing to see, let\'s go.”" << endl;
    }
}