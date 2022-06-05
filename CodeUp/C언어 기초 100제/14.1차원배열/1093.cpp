#include <iostream>

using namespace std;

int main(){

    int n, t;
    int arr[24] = {0, };
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> t;
        arr[t] += 1;
    }
    
    for (int i=1; i<=23; i++){
        cout << arr[i] << ' ';
    }
    
    return 0;
}