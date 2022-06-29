#include <iostream>
// 브론즈3

using namespace std;

int arr[4];
int money[4] = {25, 10, 5, 1};

int change(int C, int num){
    arr[num] = C/money[num];
    C-=(C/money[num])*money[num];
    return C;
}

int main(){

    int T, C, a=25, b=10, c=5, d=1;
    cin >> T;
    for(int i=0; i<T; i++){

        cin >> C;
        for (int j=0; j<4; j++)
            arr[j] = 0;

        if(C/money[0]>0){
            C = change(C, 0);
        } 

        if(C/money[1]>0){
            C = change(C, 1);
        } 
        if(C/money[2]>0){
            C = change(C, 2);
        }         
        if(C/money[3]>0){
            C = change(C, 3);
        } 

        for (int j=0; j<4; j++)
            cout << arr[j] << ' ';
        cout << '\n';
    }
    return 0;
}