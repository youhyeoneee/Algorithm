#include <iostream>

using namespace std;

int main(){

    int n, x, y;
    int arr[20][20] = {0, };

    //입력
    for (int i=1; i<=19; i++){
        for (int j=1; j<=19; j++){
            cin >> arr[i][j];
        }
     }
  
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> x >> y;
        // 십자뒤집기
        
        for (int j=1; j<=19; j++){
            // 가로 
            if(arr[x][j]==0) 
                arr[x][j]= 1 ;
            else 
                arr[x][j] = 0;

            // 세로
            if(arr[j][y] == 0)
                arr[j][y] = 1;
            else
                arr[j][y] = 0;
        }
    }
    

    // 출력
    for (int i=1; i<=19; i++){
        for (int j=1; j<=19; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
     }
    return 0;
}