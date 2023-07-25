#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
int arr[8][8];
bool visited[8][8];
int mmax = 0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> wallVec;
vector<pair<int, int>> virusVec;

void Input()
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0) wallVec.push_back({i, j});
            else if (arr[i][j] == 2) virusVec.push_back({i, j});
        }
    }

}

void Init()
{
    memset(visited, false, sizeof(visited));
}

void Dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1 || visited[ny][nx])
            continue;
        
        Dfs(ny, nx);
    }

    return;
}

int Count()
{
    int cnt = 0;
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<M; x++)
        {
            if (arr[y][x] == 0 && !visited[y][x]) cnt++;
        }
    }


    return cnt;
}

void Solve()
{
    for(int i=0; i<wallVec.size(); i++)
    {
        for(int j=i+1; j<wallVec.size(); j++)
        {
            for(int k=j+1; k<wallVec.size(); k++)
            {   
                arr[wallVec[i].first][wallVec[i].second] = 1;
                arr[wallVec[j].first][wallVec[j].second] = 1;
                arr[wallVec[k].first][wallVec[k].second] = 1;

                Init();
                

                for(auto pos : virusVec)
                {
                    Dfs(pos.first, pos.second);
                }

                int cnt = Count();
                mmax = max(cnt, mmax);

                arr[wallVec[i].first][wallVec[i].second] = 0;
                arr[wallVec[j].first][wallVec[j].second] = 0;
                arr[wallVec[k].first][wallVec[k].second] = 0;

            }
        }
    }

    cout << mmax;
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