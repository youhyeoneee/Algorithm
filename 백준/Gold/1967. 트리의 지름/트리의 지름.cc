#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

#define MAX 10004

using namespace std;

int parents[MAX];
int levels[MAX];
unordered_map<int, vector<pair<int, int>>> childs; // 자식 - 가중치

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(int &n, vector<pair<pair<int, int>, int>> &edges) {
    cin >> n;
    int parent, child, weight;
    for(int i=0; i<n-1; i++) {
        cin >> parent >> child >> weight;
        edges.push_back({{parent, child}, weight});
    }
}

int lca(int a, int b) {
    // a를 더 level이 높은 정점으로 맞춘다.
    if (levels[a] < levels[b]) swap(a, b);

    // 두 정점의 level을 같게 만들기
    while (levels[a] != levels[b]) {
        a = parents[a];
    }

    // 가리키는 정점이 같아질 때까지 거슬러 올라가기
    while (a != b) {
        a = parents[a];
        b = parents[b];
    }

    return a;
}

int getWeight(int parent, int child) {
    for(auto i : childs[parent]) {
        if (i.first == child) return i.second;
    }

    return 0;
}

int getLength(int start, int root) {
    int length = 0;
    while(start != root) {
        length += getWeight(parents[start], start);
        start = parents[start];
    }

    return length;
}

int solve(int &n, vector<pair<pair<int, int>, int>> &edges) {

    if (n == 1) {
        return 0;
    }

    vector<int> leafNodes;
    int root = 1;

    for(auto edge : edges) {
        int parent = edge.first.first;
        int child = edge.first.second;
        int weight = edge.second;

        childs[parent].push_back({child, weight});
        parents[child] = parent;
    }

    // 리프 노드 리스트 만들기
    for(int i=1; i<=n; i++) {
        if (childs[i].size() == 0) {
            leafNodes.push_back(i);
        }
    }

    // levels 설정하기
    stack<pair<int, int>> s;
    s.push({root, 0}); // 루트 노드, 레벨 0

    while(!s.empty()) {
        pair<int, int> curr = s.top();
        int node = curr.first;
        int level = curr.second;
        levels[node] = level;

        s.pop();

        if (childs.find(node) != childs.end()) {
            for(auto child : childs[node]) {
                s.push({child.first, level+1});
            }
        }
    }

    int rootToLeaf = 0;
    int t;
    // 아무 점이나 잡고(루트), 이 점에서 가장 거리가 먼 점 t 를 잡는다
    for(int i=0; i<leafNodes.size(); i++) {
        
        int length = getLength(leafNodes[i], root);

        if (rootToLeaf < length) {
            rootToLeaf = length;  // t ~ root
            t = leafNodes[i];
        }  
    }

    int answer = 0;
    // t에서 가장 거리가 먼점 u 를 찾는다
    for(int i=0; i<leafNodes.size(); i++) {

        int u = leafNodes[i];
        if (t == u)
            continue;
        
        int lcaNode = lca(t, u);
        int length = getLength(t, lcaNode) + getLength(u, lcaNode);
        answer = max(answer, length);
    }

    // root 노드와도 비교한다.
    answer = max(answer, getLength(t, root));

    return answer;
}

void output(int answer) {
    cout << answer << '\n';
}

int main() {
    int n;
    vector<pair<pair<int, int>, int>> edges; // {부모 - 노드, 가중치} 의 리스트
    fastIO();
    input(n, edges);
    output(solve(n, edges));

    return 0;
}
