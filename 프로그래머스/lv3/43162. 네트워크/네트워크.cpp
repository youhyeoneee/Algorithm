#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
 
bool visited[201]; // 방문 체크 배열

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 모든 컴퓨터를 돌면서
    for(int i=0; i<n; i++)
    {
        // 방문하지 않았다면 시작
        if (!visited[i])
        {
            answer++;
            stack<int> s;
            s.push(i);
            
            while(!s.empty())
            {
                int curr = s.top();
                s.pop();
                visited[curr] = true; 
                
                for(int next=0; next<n; next++)
                {
                    // 방문하지 않고 연결되어 있을 때
                    if (!visited[next] && computers[curr][next])
                        s.push(next);
                }
                
            }
        }
        
    }
    
    return answer;
}