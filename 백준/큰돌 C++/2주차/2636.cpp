#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
int arr[100][100];
bool visited[100][100];
vector<pair<int, int>> cheese;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int result;

void Input()
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
    }

}

void Dfs(int y, int x)
{
    visited[y][x] = true;
    if (arr[y][x] == 1)
    {
        cheese.push_back({y, x});
        return;
    }

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
            continue;

        Dfs(ny, nx);
    }

    return;
}

void Init()
{
    memset(visited, 0, sizeof(visited));
    cheese.clear();
}

bool IsCheeseInMap()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if (arr[i][j] == 1) return true;
        }
    }

    return false;
}

void Solve()
{
    int time = 0; 
    int cnt;

    while(true)
    {

        Init();
        
        Dfs(0, 0);  

        cnt = cheese.size();

        time++;

        for(auto pos : cheese)
        {
            arr[pos.first][pos.second] = 0;
        }

        if (!IsCheeseInMap())
            break;

    }

    cout << time << '\n' << cnt;
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