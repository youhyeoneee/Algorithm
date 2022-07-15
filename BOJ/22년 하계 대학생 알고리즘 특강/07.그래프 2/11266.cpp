#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// A. 단절점

int V, E; // 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다
int a, b;
stack<int> s;
vector<int> G[10001];

int order = 0;
int visited[10001] = {0, }; // order 저장
int dfs(int curr, int parent){

    visited[curr] = ++order; // 방문 order 저장
    int child = 0;

    for(int next : G[curr]){
        if (next == parent) continue;

        // 부모 노드가 아닌 경우 next에 방문 시도를 해 본다.
        if (visited[next] > 0)  // next 가 이미 방문을 한 노드인 경우
            minOrder = (visited[next] < minOrder)? visited[next] : minOrder;
            // DST 의 관점에서 보면 이러한 노드들은 curr의 조상인 경우 외엔 존재할 수 없다.
            // 다시 말해, next 노드는 현재 dfs 작업이 끝난 상태가 아니므로, 
            // next 노드에서의 유효한 order 값은 visited[next] 가 유일하다.

        else { // next 가 미 방문 상태인 경우
            chilt++;
            int low = dfs(next, curr);

             if (parent != 0 && visited[curr] <= low) CutVertex[curr] = 1;

        }
}
}
return lo


int main(){

    cin >> V >> E;

    for(int i=0; i<E; i++){
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);
 
    return 0;
}