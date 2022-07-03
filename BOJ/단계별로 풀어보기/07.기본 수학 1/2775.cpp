#include <iostream>

using namespace std;

int main(){

    int T, k, n;

    int arr[15][15];

    // 0층 i호
    for(int i=1; i<=14; i++)
        arr[0][i] = i;

    for(int i=1; i<=14; i++){ // i층 j호
        int sum = 0;
        for(int j=1; j<=14; j++){
            sum += arr[i-1][j];
            arr[i][j] = sum;
        }
    }

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> k;
        cin >> n;
        cout << arr[k][n] << '\n';
    }
    return 0;
}