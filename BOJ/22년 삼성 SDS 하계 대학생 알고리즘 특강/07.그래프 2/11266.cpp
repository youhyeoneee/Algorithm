#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// A. 단절점

int V, E, a, b; // 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다
vector<int> AL[10001]; // 인접 리스트

int visit_order[10001]; // 방문 순서 저장됨. 미방문 = 0 
int cut_vertex[10001]; // 각 정점이 단절점인지의 여부 저장
vector<int> result; // 단절점 정보

int order = 0; // 방문 순서 

int dfs(int curr, int parent){ // 현재 노드의 low 반환해야 함.
    visit_order[curr] = ++order; // 방문 순서 저장

    // 내 부모에게 넘겨줄 low (현재 나의 return 값) 저장하는 변수
    // 나와 연결된 점을 방문했을 때 방문한 연결 점이 방문했던 점들 중 order가 가장 빠름. 
    int min_order = visit_order[curr]; 
    
    // child의 개수 저장
    int child = 0;

    for (int next : AL[curr]){
        if (next == parent) continue; // 부모 노드 인 경우 pass
        if (visit_order[next] > 0){ // 다음 정점이 이미 방문한 정점일 경우

            // min order 갱신

            min_order = (visit_order[next] < min_order)? visit_order[next] : min_order;
        }
        else{ // 다음 정점이 아직 미방문인 경우
            ++child;
            int low = dfs(next, curr);

            if (parent != 0 && visit_order[curr] <= low) cut_vertex[curr] = 1;
            
            min_order = (low < min_order)? low : min_order;
        }
    }

    if (parent == 0 && child >= 2) cut_vertex[curr] = 1;
    return min_order;
}

// 단절점 판단 : 부모와 자식이 나를 통해 연결이 되어 있는가!!


int main(){

    // input
    cin >> V >> E;

    for(int i=0; i<E; i++){
        cin >> a >> b;

        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    // processing

    for(int i=1; i<=V; i++){ 
        // 부모노드 같이 들고 다니면서 저장
        if (visit_order[i] == 0) dfs(i, 0);
    }

    for(int i=1; i<=V; i++){
        if (cut_vertex[i]) result.push_back(i);
    }

    // output


    // 첫째 줄에 단절점의 개수를 출력한다.
    cout << result.size() << '\n';

    // 둘째 줄에는 단절점의 번호를 공백으로 구분해 오름차순으로 출력한다.
    for(int i : result){
        cout << i << " ";
    }
    return 0;
}