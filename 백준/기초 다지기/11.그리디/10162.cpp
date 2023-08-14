#include <iostream>

// 브론즈4

using namespace std;

int main(){

    int T;

    cin >> T;

    int arr[3] = {0, }; // 차례대로 A, B, C 누른 횟수

    if (T%10 == 0){
        if (T>=300){
            arr[0] = T/300;
            T-=(T/300)*300;
        }
        if (T>=60){
            arr[1] = T/60;
            T-=(T/60)*60;
        }
        if (T>=10){
            arr[2] = T/10;
        }

        for(int i=0; i<3; i++){
            cout << arr[i] << ' ';
        }
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}