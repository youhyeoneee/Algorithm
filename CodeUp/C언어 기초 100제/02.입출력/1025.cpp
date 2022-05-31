#include <iostream>
#include <string>

using namespace std;

int main(){

    string s;

    cin >> s;
    for (int i=0; i<5; i++){
        string temp;
        for (int j=0; j<4-i; j++)
            temp += '0';
        cout << "[" << s[i] << temp << "]" << endl;

    }
}