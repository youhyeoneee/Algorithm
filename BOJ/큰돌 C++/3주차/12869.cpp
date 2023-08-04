#include <iostream>
#include <queue>

#define MAX 64
#define INF 987654321   
using namespace std;

int arr[3];
int N;

int visited[MAX][MAX][MAX];

int attack[6][3] = 
{
    {9, 3, 1},
    {3, 9, 1},
    {9, 1, 3},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3},
};

struct SCV
{
    int a, b, c;
};

queue<SCV> q;

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    q.push({arr[0], arr[1], arr[2]});
    visited[arr[0]][arr[1]][arr[2]] = 1;

    while(!q.empty())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (visited[0][0][0]) break;

        for(int i=0; i<6; i++)
        {
            // 인덱스 음수 안되게 하기 위해
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);

            if (visited[na][nb][nc])
                continue;
            
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }

    }

    cout << visited[0][0][0] - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}   