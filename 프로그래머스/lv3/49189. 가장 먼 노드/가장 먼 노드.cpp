#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[20001]; // 인접 리스트
int visited[20001]; // 방문여부

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(vector<int> e : edge)
    {
        
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int maxx = 0;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int next : adj[curr])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = visited[curr] + 1;
                maxx = max(maxx, visited[next]);
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if (visited[i] == maxx) answer++;
    }
    return answer;
}