#include <iostream>
#include <queue>

#define MAX 1000+4
#define INF 987654321
#define DIR_NUM 4
using namespace std;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2];
int b[MAX][MAX];

int dy[DIR_NUM] = {0, 1, 0, -1};
int dx[DIR_NUM] = {1, 0, -1, 0};
int answer = INF;

bool OutOfRange(int y, int x) {
    return (y < 0) || (x < 0) || (y >= N) || (x >= M);
}

int main() {
    cin >> N >> M;

    char ch;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }
    
    queue<pair<pair<int, int>, bool>> q;
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    q.push({{0, 0}, false});

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool crashed = q.front().second;
        // cout << y << "," << x << ":" << map[y][x] << " - visited " << visited[y][x][crashed] << ", crashed : " << crashed << "\n"; 
        q.pop();

        if (y == N-1 && x == M-1) {
            answer = min(answer, visited[N-1][M-1][crashed]);
            // cout << "===============\n";

        } else {
            for(int i=0; i<DIR_NUM; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                // 범위 밖이거나 이미 방문한경우 
                if (OutOfRange(ny, nx) || visited[ny][nx][crashed]) {
                    continue;
                } 

                // 벽이고 부술 수 있는 경우
                if (map[ny][nx] && !crashed) {
                    q.push({{ny, nx}, true});
                    visited[ny][nx][true] = visited[y][x][false] + 1; 
                } else if (!map[ny][nx]) { // 벽이 아닌 경우
                    q.push({{ny, nx}, crashed});
                    visited[ny][nx][crashed] = visited[y][x][crashed] + 1;
                }
            }
        }


    }
    
    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer;
    }


    return 0; 
}

