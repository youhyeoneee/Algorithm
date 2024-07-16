#include <iostream>

using namespace std;

int N, M; 
// 0 <= y < N (행)
// 0 <= x < M (열)

int answer = 0;
int map[26][26];

// 상, 좌상, 좌
int dx[3] = {0, -1, -1};
int dy[3] = {-1, -1, 0};


bool makeNemmo(int x, int y) {
    int cnt = 0;
    for(int i=0; i<3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (map[ny][nx]) cnt++; 
    }

    return cnt == 3;
}

void backtracking(int x, int y) {

    // 맨 마지막 
    if (x == M && y == N-1) {
        answer++;
        return;
    }

    // 다음 행으로 
    if (x == M) {
        x = 0;
        y++;
    }

    // 넴모 놓기 
    map[y][x] = 1; 

    // 넴모가 만들어지지 않으면 놓은 채로 넘어간다.
    if (!makeNemmo(x, y)) {
        backtracking(x+1, y);
    }

    // 넴모 빼기
    map[y][x] = 0;
    backtracking(x+1, y);
    
}

int main() {
    cin >> N >> M;

    backtracking(0, 0);

    cout << answer;
}