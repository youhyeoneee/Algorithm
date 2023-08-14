#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;
int temp;
int key;
int root;

vector<int> adj[54]; 

void Input()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> temp;
        if (temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    
    cin >> key;
}


int Dfs(int here)
{
    int result = 0;
    int child = 0;

    for(int there : adj[here])
    {
        if (there == key) continue;
        result += Dfs(there);
        child++;
    }

    if (child == 0) return 1;

    return result;
}

void Solve()
{
    if (key == root) cout << 0;
    else cout << Dfs(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Input();
    Solve();
}