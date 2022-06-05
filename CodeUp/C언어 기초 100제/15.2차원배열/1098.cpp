#include <iostream>

using namespace std;

int main(){

    int h, w, n, l, d, x, y;

    // 격자판의 세로(h), 가로(w), 막대의 개수(n), 각 막대의 길이(l),
    // 막대를 놓는 방향(d:가로는 0, 세로는 1)과
    // 막대를 놓는 막대의 가장 왼쪽 또는 위쪽의 위치(x, y)
    int arr[101][101] = {0, };


    // 입력
    cin >> h >> w;
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> l >> d >> x >> y;
        
        // 세로
        if (d){
            for (int j=x; j<x+l; j++){
                if (arr[j][y] == 0)
                    arr[j][y] = 1;
            }
        }
        else{ // 가로
            for (int j=y; j<y+l; j++){
                if (arr[x][j] == 0)
                    arr[x][j] = 1;
            }
        }
    }
    // 출력
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}