#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int N, K;

int visited[MAX+4];
int prevArr[MAX+4];


void Input()
{
    cin >> N >> K;
}

void Solve()
{
    // BFS 

    queue<int> q;
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
                    visited[next] = visited[curr] + 1; // 방문 처리
                    prevArr[next] = curr; // 이전 것을 등록하여 역추적 
                }
                
            }
        }
    }
    
    cout << visited[K] - 1 << '\n';


    // 도착 지점에서 역추적하면서 벡터에 넣는다.
    vector<int> v;

    for(int i = K; i != N; i = prevArr[i])
    {
        v.push_back(i);
    }
    v.push_back(N); // 시작 지점도 넣기

    // 거꾸로 뒤집기 
    reverse(v.begin(), v.end());

    for(int i : v) cout << i << " ";


}

int main()
{
    Input();
    Solve();

    return 0;
}