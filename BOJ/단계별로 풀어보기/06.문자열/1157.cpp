#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;

    cin >> str;

    for(char ch : str){
        cout << (int)ch << '\n';
    }

    return 0;
}