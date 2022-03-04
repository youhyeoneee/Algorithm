#include <iostream>
#include <string>

using namespace std;

int main(){

    string text;

    while (true)
    {
        getline(cin, text);
        if(text == "")
            break;
        cout << text <<endl;
    }

    return 0;
}