#include <iostream>

using namespace std;

int main(){

    long A, B, C, cnt;

    cin >> A >> B >> C;

    // A + (B*개수) < C*개수 
    // A < (C-B)*개수
    // A/(C-B) < 개수

    if (B >= C)
        cout << -1;
    else 
        cout << (A/(C-B))+1 << '\n';
    
    return 0;
}