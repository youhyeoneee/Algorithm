#include <iostream>

using namespace std;

int main(){

    int n, x, y;
    int arr[20][20] = {0, };
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> x >> y;
        if (arr[x][y] == 0)
            arr[x][y] += 1;
    }
    
     for (int i=1; i<=19; i++){
        for (int j=1; j<=19; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
     }
    return 0;
}