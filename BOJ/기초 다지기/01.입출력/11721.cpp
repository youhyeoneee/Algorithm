
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string text;
    cin >> text;

    for(int i=0; i<text.length(); i++){
            cout << text[i];
        if (i%10 == 9)
            cout << endl;
    }

    return 0;
}