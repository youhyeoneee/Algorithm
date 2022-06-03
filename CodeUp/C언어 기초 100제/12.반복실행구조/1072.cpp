#include <iostream>

using namespace std;

int main(){

    int n, a;

    cin >> n;


    reload:
        cin >> a;
        cout << a << '\n';

        if (--n!= 0) goto reload;
        
    
    return 0;
}