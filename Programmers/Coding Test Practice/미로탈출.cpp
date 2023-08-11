#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define INF 2000000
using namespace std;

int visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int X, Y;

pair<int, int> startPos;
pair<int, int> leverPos;
pair<int, int> endPos;

void Bfs(queue<pair<int, int>> &q, vector<string> &maps)
{
    // 방문 배열
    // BFS
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 영역 내, 벽 체크
            if (ny < 0 || nx < 0 || ny >= Y || nx >= X || maps[ny][nx] == 'X')
                continue;

            // 방문 체크 
            if (visited[ny][nx] == INF)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int solution(vector<string> maps) {
    
    int answer = INF;
    X = maps[0].length();
    Y = maps.size();

     
    // 시작 지점, 레버, 도착 지점 저장
    for(int y=0; y<Y; y++)
    {
        for(int x=0; x<X; x++)
        {
            if (maps[y][x] == 'S') startPos = {y, x};
            else if (maps[y][x] == 'L') leverPos = {y, x};
            else if (maps[y][x] == 'E') endPos = {y, x};
        }
    }

                
    fill(&visited[0][0], &visited[0][0] + 104 * 104, INF);
    
    // 시작 지점에서 출발
    queue<pair<int, int>> q;
    q.push(startPos);
    visited[startPos.first][startPos.second] = 0;
    
    Bfs(q, maps);
    // 출발 -> 레버 
    int lever = visited[leverPos.first][leverPos.second];
    
    if (lever == INF)
    {
        answer = -1;
        return answer;
    }
    else answer = min(answer, lever);
    
    // 레버 -> 도착 
    fill(&visited[0][0], &visited[0][0] + 104 * 104, INF);
    queue<pair<int, int>> q2;
    q2.push(leverPos);
    visited[leverPos.first][leverPos.second] = 0;
    
    Bfs(q2, maps);
    
    int end = visited[endPos.first][endPos.second];

    if (end == INF)
    {
        answer = -1;
        return answer;
    }
    else answer += end;
    

    return answer;
}

