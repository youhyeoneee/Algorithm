#include <iostream>
#include <string>
#include <queue>

#define MAX 1004
#define INF 987654321
using namespace std;

char map[MAX][MAX];
int R, C;

pair<int, int> jihunPos;
queue<pair<int, int>> q;

int jihunVisited[MAX][MAX];
int fireVisited[MAX][MAX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int result = 0;

void Input()
{

    fill(&fireVisited[0][0], &fireVisited[0][0] + MAX * MAX, INF);

    cin >> R >> C;

    for(int i=0; i<R; i++)
    {
        string str;
        cin >> str;

        for(int j=0; j<C; j++)
        {
            map[i][j] = str[j];
            if (str[j] == 'J')
                jihunPos = {i, j};
            else if (str[j] == 'F')
            {
                fireVisited[i][j] = 1;
                q.push({i, j});
            }
        }
    }
}

void Solve()
{
    // 불 BFS
    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];

            // 범위 초과
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;

            // 방문했거나 벽인 경우
            if (fireVisited[ny][nx] != INF || map[ny][nx] == '#')
                continue;

            fireVisited[ny][nx] = fireVisited[curr.first][curr.second] + 1;
            q.push({ny, nx});
        }
    }
    
    // 지훈 BFS
    q.push(jihunPos);
    jihunVisited[jihunPos.first][jihunPos.second] = 1;

    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        int y = curr.first;
        int x = curr.second;
        q.pop();

        // 가장자리 
        if (y == R-1 || y == 0 || x == C-1 || x == 0)
        {
            result = jihunVisited[y][x];
            break;
        }
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 초과
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;

            // 방문했거나 벽인 경우
            if (jihunVisited[ny][nx] || map[ny][nx] == '#')
                continue;

            // 불이 더 빨리 온 경우
            if (fireVisited[ny][nx] <= jihunVisited[y][x] + 1)
                continue;
                
            jihunVisited[ny][nx] = jihunVisited[curr.first][curr.second] + 1;
            q.push({ny, nx});
        }
    }

    if (result != 0)   cout << result;
    else cout << "IMPOSSIBLE";

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