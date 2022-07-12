#include <iostream>
#include <vector>
#include <algorithm>

// 네트워크 연결

using namespace std;

int N, M, a, b, c, result = 0;

vector<int> edge[100001]; // 간선 리스트
int parent[10001];

int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void join(int a, int b){ // Union
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = root_b;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int main(){

    cin >> N; //  컴퓨터의 수
    cin >> M; //  연결할 수 있는 선의 수 
    for(int i=0; i<M; i++){
        // a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다
        cin >> a >> b >> c;
        edge[i].push_back(a);
        edge[i].push_back(b);
        edge[i].push_back(c);
    }

    // init 
    for(int i=1; i<=N; i++)
        parent[i] = i;

    // 오름차순 정렬
    sort(edge, edge+M, compare);

    for(int i=0; i<M; i++){        
        int start = edge[i][0];
        int end = edge[i][1];
        if (find(start) != find(end)) {
            // 연결되어 있지 않으면 join
            join(start, end); 
            result += edge[i][2]; // cost
        }
    }

    cout << result;

    return 0;
}