#include <iostream>
#include <string>
#include <queue>

using namespace std;


const int SIZE = 101;

int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int N, M;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void Input()
{
    cin >> N >> M;

    string str;

    for(int i=0; i<N; i++)
    {
        cin >> str;

        for(int j=0; j<M; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }

}

void Solve()
{
    int x = 0, y = 0;

    queue<pair<int, int>> q;

    visited[y][x] = 1;
    q.push({y, x});

    while(q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];


            // 범위 초과, 길 없음, 이미 방문
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || !map[ny][nx] || visited[ny][nx])
                continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[N-1][M-1];
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}