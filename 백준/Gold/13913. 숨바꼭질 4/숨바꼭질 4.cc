#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define MAX 100000

using namespace std;

int N, K;

int visited[MAX+4];
vector<int> adj[MAX+4];


void Input()
{
    cin >> N >> K;
}

void Solve()
{
    queue<int> q;

    // BFS 

    q.push(N);
    visited[N] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        // 도착했을 경우
        if (curr == K)
            break;

        // 1초 후 이동 범위 
        for (int next : {curr-1, curr+1, curr*2})
        {
            // 범위 안에 있을 때
            if (0 <= next && next <= MAX)
            {
                // 방문하지 않았다면
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = visited[curr] + 1;
                    adj[next].push_back(curr);
                }
                
            }
        }
    }
    
    cout << visited[K] - 1 << '\n';


    int curr = K;

    stack<int> s;
    s.push(curr);

    while(curr != N)
    {
        for(int i : adj[curr])
        {   
            curr = i;
            s.push(curr);
        }
    }
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

}

int main()
{
    Input();
    Solve();

    return 0;
}