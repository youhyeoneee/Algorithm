#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int N, L, R;
int map[54][54];
int visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int sum = 0;
vector<pair<int, int>> v;

void Input()
{
    cin >> N >> L >> R;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void Dfs(int y, int x, vector<pair<int, int>> &v)
{
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i]; 
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])
            continue;

        int diff = abs(map[ny][nx] - map[y][x]);
        if (L <= diff && diff <= R)
        {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += map[ny][nx];
            Dfs(ny, nx, v);
        }
    }
}

void Solve()
{
    int cnt = 0;
    while (true)
    {
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if (!visited[i][j]) 
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = map[i][j];

                    Dfs(i, j, v);

                    if (v.size() == 1) continue;

                    int avg = sum/v.size();
                    for(auto pos : v)
                    {
                        map[pos.first][pos.second] = avg;
                        flag = true;
                    }
                }
            }
        }

        if (!flag) break;
        cnt++;
    }
    
    cout << cnt << '\n';

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