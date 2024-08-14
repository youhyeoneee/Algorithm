#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> adj[100004];

int visited[100004];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(vector<int> road : roads) {
        int a = road[0], b = road[1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
        
    // destination에서 갈 수 있는 모든 곳 dfs로 구하기
    // 지역, 깊이 
    queue<pair<int, int>> q;
    q.push({destination, 1});
    visited[destination] = 1;

    while(!q.empty()) {
        int curr = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        for(int next : adj[curr]) {
            if (visited[next])
                continue; 
            
            visited[next] = depth + 1;
            q.push({next, depth + 1}); 
        }
        
    }
    
    for(int source : sources) {
        answer.push_back(visited[source]-1);
    }
    
    return answer;
}