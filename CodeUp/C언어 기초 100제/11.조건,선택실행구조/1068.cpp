#include <iostream>

using namespace std;

int main(){

    int a;
    cin >> a;
    
    if (a>=90)
        cout << "A" << '\n';
    else if (a>= 70)
        cout << "B" << '\n';
    else if (a>= 40)
        cout << "C" << '\n';
    else    
        cout << "D" << '\n';

    return 0;
}

  