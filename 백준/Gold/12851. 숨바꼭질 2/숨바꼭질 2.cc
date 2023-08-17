#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
#define MAX 100000
using namespace std;

int N, K;

int cnt[MAX+4];
int visited[MAX+4]; // 도달하는 최소 시간을 담은 배열

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Input()
{
    cin >> N >> K;
}


void Solve()
{    
    // 위치, 시간
    queue<int> q;

    q.push(N); 
    visited[N] = 1;
    cnt[N] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == K)
            break;

        for(int next : {curr-1, curr+1, curr*2})
        {
            // 범위 안에 있을 때만
            if (0 <= next && next <= MAX)
            {
                // 방문하지 않았을 때
                if (!visited[next])
                {
                    q.push(next);        
                    cnt[next] += cnt[curr];
                    visited[next] = visited[curr] + 1;
                }
                else if (visited[next] == visited[curr] + 1)  
                {
                    cnt[next] += cnt[curr];
                }
            }
        }
    }
    

    cout << visited[K] - 1 << '\n' << cnt[K];

}

int main()
{
    FastIO();
    Input();
    Solve();

    return 0;
}
