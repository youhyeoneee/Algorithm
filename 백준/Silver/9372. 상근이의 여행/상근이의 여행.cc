#include <iostream>
#include <vector> 

using namespace std;

int T, N, M; 
vector<int> adj[10000];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;
    int a, b;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
}

int solve(int N, int M, vector<int> airplanes[]) {
    return N-1;
}

void output(int answer) {
    cout << answer << '\n';
}

int main() {
    fastIO();

    cin >> T;
    for(int i=0; i<T; i++) {
        input();
        output(solve(N, M, adj));
    }   

}