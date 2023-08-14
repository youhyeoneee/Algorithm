#include <iostream>

using namespace std;

const int SIZE = 101;

int map[SIZE][SIZE];
bool visited[SIZE][SIZE];
int N;
int minHeight = 101;
int maxHeight = 0;
int result = 1;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void Init()
{
    fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
}

void Input()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > maxHeight)
                maxHeight = map[i][j];

            if (map[i][j] < minHeight)
                minHeight = map[i][j];
        }
    }

}

void Dfs(int y, int x, int depth)
{
    visited[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[ny][nx] <= depth || visited[ny][nx])
            continue;
        
        Dfs(ny, nx, depth);
    }

    return;
}

void Solve()
{  

    for(int rain=minHeight; rain<maxHeight; rain++)
    {
        Init();

        int cnt = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if (map[i][j] > rain && !visited[i][j])
                {
                    cnt++;
                    Dfs(i, j, rain);
                }
            }
        }
        
        if (cnt > result) result = cnt;

    }

    cout << result;
    
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