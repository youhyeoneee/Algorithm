#include <iostream>

using namespace std;

int main(){

    
    int arr[11][11] = {0, };


    // 입력
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            cin >> arr[i][j];
        }
    }


    int x=2, y=2; // 개미 이동 경로
    bool found = false; // 찾았는지

    while(!found){
         // 먹이 찾은 경우 
        if (arr[x][y] == 2){
            found = true;
        }

        // 더 이상 움직일 수 없는 경우
        if (arr[x][y+1] == 1 && arr[x+1][y] == 1){
            found = true;
        }
            
        //  맨 아래의 가장 오른쪽에 도착한 경우
        if (x==10 && y==10){
            found = true;
        }
             
        arr[x][y] = 9;

        // 방향
        if (arr[x][y+1] == 1)
            x++;
        else
            y++;
           
    
    }

    // 출력
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}