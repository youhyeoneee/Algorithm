#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M, A, B;

vector<int> arr[10004];
bool visited[10004];
vector<int> hack[10004];
int mmax = -1;

void Input()
{   

    cin >> N >> M;

    for(int i=0; i<M; i++)
    {
        cin >> A >> B;

        arr[B].push_back(A);
    }

}

int Dfs(int here)
{
    int result = 1;
    visited[here] = true;

    for (auto there : arr[here])
    {
        if (visited[there]) continue;
        result += Dfs(there);
    }
    
    return result;
}

void Solve()
{
    for(int i=1; i<=N; i++)
    {
        memset(visited, false, sizeof(visited));
        int result = Dfs(i);
        mmax = max(result, mmax);
        hack[result].push_back(i);
    }

    for(auto j : hack[mmax])
    {
        cout << j << " ";
    }
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