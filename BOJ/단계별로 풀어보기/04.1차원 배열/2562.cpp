#include <iostream>

using namespace std;

int main(){

    int max = 0, idx;
    int arr[9];
    for (int i=0; i<9; i++){
        cin >> arr[i];
        if(arr[i] > max) { max = arr[i]; idx = i;}
    }

    cout << max << '\n' << idx+1;
    return 0;
}