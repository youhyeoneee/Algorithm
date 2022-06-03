#include <iostream>

using namespace std;

int main(){

    int a;

    reload:
        cin >> a;

        if (a != 0) {
            cout << a << '\n';
            goto reload;
        }
        
    
    return 0;
}