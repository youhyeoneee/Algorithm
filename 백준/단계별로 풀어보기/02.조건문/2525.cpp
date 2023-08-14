#include <iostream>

using namespace std;

int main(){

    int A, B, C;

    cin >> A >> B; // 현재 시각
    cin >> C; // 요리하는 데 필요한 시간

    A += (C/60);
    B += (C%60);

    if (B > 59) { B -= 60; A += 1; }
    if (A > 23) A -= 24;

    cout << A << " " << B;
    
    return 0;
}