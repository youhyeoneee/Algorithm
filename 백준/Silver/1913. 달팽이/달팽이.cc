#include <iostream>
#include <cmath>

using namespace std;

int map[1000][1000];
int N, X;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {

    cin >> N;
    cin >> X;

    int dirIdx = 0, x = 0, y = 0;
    int num = pow(N, 2);

    int ny, nx;

    while(num > 0) {
        // 채워 넣기
        map[y][x] = num;

        num--;      

        ny = y + dy[dirIdx];
        nx = x + dx[dirIdx];

        // 벽에 부딛히거나 이미 숫자가 존재한다면 방향 전환
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx]) {
            dirIdx = (dirIdx + 1) % 4; 
        }

        y = y + dy[dirIdx];
        x = x + dx[dirIdx];
    }

    int answerX, answerY;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j] << " ";

            if (map[i][j] == X) {
                answerY = i + 1;
                answerX = j + 1;
            }

        }
        cout << "\n";
    }

    cout << answerY << " " << answerX << "\n";

    return 0;
}