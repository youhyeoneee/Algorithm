#include <iostream>

using namespace std;

int main(){

    int n, k;
    int arr[10001] = {0, };
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> k;
        arr[i] = k;
    }
    
    for (int i=n; i>=1; i--){
        cout << arr[i] << ' ';
    }
    
    return 0;
}