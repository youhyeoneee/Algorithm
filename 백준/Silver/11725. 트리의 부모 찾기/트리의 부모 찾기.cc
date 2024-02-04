#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int N;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<int>> input() {
    vector<vector<int>> v;

    cin >> N;

    int a, b;
    for(int i=0; i<N-1; i++) {
        vector<int> temp;
        cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }

    return v;
}

vector<int> solve(int N, vector<vector<int>> nodes) {
    vector<int> answer(N+1);
    vector<vector<int>> adj(N+1); 
    vector<bool> visited(N+1);

    for(auto v : nodes) {  
        int a = v[0];
        int b = v[1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> s;
    s.push(1);

    while(!s.empty()) {
        int curr = s.top();
        visited[curr] = true;
        s.pop();

        for(int next : adj[curr]) {
            if (!visited[next]) {
                answer[next] = curr;
                s.push(next);
            }
        }
    }
    return answer;
}

void output(vector<int> answer) {
    for(int i=2; i<=N; i++) {
        cout << answer[i] << '\n';
    }
}

int main() {
    fastIO();
    vector<vector<int>> nodes = input();
    output(solve(N, nodes));

    return 0;
}