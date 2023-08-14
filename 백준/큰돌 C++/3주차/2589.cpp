#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

char map[54][54];
int visited[54][54];

int H, W;
vector<pair<int, int>> landVec;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int maxdistance = -1;

void Input()
{
    cin >> H >> W;

    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'L')
                landVec.push_back({i, j});
        }
    }
}

void Solve()
{
    for(int i=0; i<landVec.size(); i++)
    {
        memset(visited, 0, sizeof(visited));

        pair<int, int> startPos = landVec[i];

        queue<pair<int, int>> q;   
        q.push(startPos);
        visited[startPos.first][startPos.second] = 1;

        while(!q.empty())
        {
            int y = q.front().first; 
            int x = q.front().second; 
            q.pop();

            for(int k=0; k<4; k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny < 0 || ny >= H || nx < 0 || nx >= W || map[ny][nx] == 'W' || visited[ny][nx] > 0)
                    continue;
                
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;

                // if (visited[ny][nx] > maxdistance)
                // {
                //     cout << "MAX >> " << startPos.first << "," << startPos.second << " ~ " << ny << "," << nx << " : " <<  visited[ny][nx] <<'\n'; 

                //        for(int i=0; i<H; i++)
                //         {
                //             for(int j=0; j<W; j++)
                //             {
                //                 cout << visited[i][j] << " ";
                //             }
                //             cout << '\n';
                //         }
                // }

                maxdistance = max(visited[ny][nx], maxdistance);

            }
        }
    }

    cout << maxdistance - 1;
   
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