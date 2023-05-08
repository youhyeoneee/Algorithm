#include <iostream>
#include <string>

using namespace std;

int main() { 

    int T;
    string str;

    cin >> T;

    for(int t=0; t<T; t++) {

        cin >> str;

        cout << str[0] << str[str.length()-1] << '\n';
    }


    return 0;
}