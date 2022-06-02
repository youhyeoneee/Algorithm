#include <iostream>

using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a<b? a:b)<c? (a<b? a:b):c) << '\n';


    return 0;
}

  