#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[101][101];

int solution(vector<vector<int>> maps)
{

    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
        
    // BFS
    int i = 0;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
                
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 영역 범위 외의 경우, 벽인 경우
            if (ny >= n || ny < 0 || nx >= m || ny < 0 || maps[ny][nx] == 0)
                continue;
            
            // 방문 안했을 경우
            if (!visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});   
            }
        }
    }
    
    
    int answer = visited[n-1][m-1];
    if (answer == 0) answer = -1;
    
    return answer;
}