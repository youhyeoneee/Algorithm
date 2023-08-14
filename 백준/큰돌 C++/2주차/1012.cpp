#include <iostream>
#include <string.h> 

using namespace std;

const int SIZE = 50;

int T, N, M, K;

bool map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void Init()
{
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
}

void Dfs(int y, int x)
{

    visited[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || !map[ny][nx] || visited[ny][nx]) continue;

        Dfs(ny, nx);
    }

    return;
}

void Solve()
{

    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                cnt++;
                Dfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
}

void Input()
{
    cin >> T;

    for(int i=0; i<T; i++)
    {
        cin >> M >> N >> K;

        Init();

        // 배추 위치
        for(int j=0; j<K; j++)
        {
            int x, y;
            cin >> x >> y;

            map[y][x] = true;
        }

        Solve();

    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    return 0;
}