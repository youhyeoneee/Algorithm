#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

// 10000 < 2^14 : 0~14
vector<int> AL[10001]; // 인접 리스트
int depth[10001]; // 깊이 저장
int tree_size[10001];
int parent[15][10001]; // [k][v] : 현재 정점 v에서 2의 k제곱번째 부모의 정점 번호를 저장
int test_case;
int T;
int E, V, child1, child2;

int LCA(int a, int b){
    // 1. depth 맞추기(항상 a의 depth가 크도록 함)

    if (depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int diff = depth[a] - depth[b];
    for(int r=0; diff; r++){ // r : 자릿수 / diff가 0이 되는 순간 빠져나옴 
        // diff가 10이면 2^3 + 2^1 => 2진수로 표현하면 1010
        if(diff & 1){ // 비트연산 & : 0이 아니면
            a = parent[r][a]; // 점프하기 
        }
        diff >>= 1; // 한 칸 내려주기 
    }
    // 2. LCA 찾기
    while(a != b){
        int r;
        for(r=0; r<18; r++){
            if(parent[r][a] == parent[r][b]) break;
        }
        if(r) --r; // r이 0이 아닌 경우에만!! 
        a = parent[r][a]; b = parent[r][b];
    }

    return a;
}

int SubTree(int a){
    deque<int> q;
    int subtree_size = 0;

    bool visited[10001] = {false, };

    q.push_back(a); // 탐색의 시작은 root

    while(!q.empty()){
        int curr = q.front(); 
        q.pop_front();
        visited[curr] = true;

        subtree_size++;
        for(int next : AL[curr]){
            if(depth[next] > depth[a] && !visited[next]){ // 자식이면
                q.push_back(next);
            }
        }
    }

    return subtree_size;
}

int main(int argc, char** argv)
{

    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{  


        // 트리의 정점의 총 수 V와 간선의 총 수 E, 공통 조상을 찾는 두 개의 정점 번호
        cin >> V >> E >> child1 >> child2;
        int a, b;
        for(int i=0; i<E; i++){
            cin >> a >> b;

            AL[a].push_back(b);
            AL[b].push_back(a);

            parent[0][b] = a;
        }

        // 전역변수로 정의된 배열을 모두 -이나 -1로 초기화 하는 방법
        memset(parent, 0, sizeof parent);
        memset(depth, 0, sizeof depth);

        // BFS를 이용하여 Depth 구현.
        for(int i=1; i<=V; i++) depth[i] = -1;  // depth -1로 모두 초기화

        deque<int> q;
        q.push_back(1); // 탐색의 시작은 root
        depth[1] = 0;
        while(!q.empty()){
            int curr = q.front(); 
            q.pop_front();
            for(int next : AL[curr]){
                if(depth[next] == -1){ // 아직 방문을 안했다면
                    q.push_back(next);
                    depth[next] = depth[curr]+1; // 무조건 next는 자식 노드이므로 +1
                    parent[0][next] = curr; // 부모 노드 등록
                }
            }
        }

        // 점핑 테이블(최소 테이블)을 만들기

        for(int r=1; r<15; r++){
            for(int i=1; i<=V; i++){
                parent[r][i] = parent[r-1][parent[r-1][i]]; // parent[r][i] = parent[r-1][i]의 2^(r-1) 번째 부모
            }
        }

        int result = LCA(child1, child2);
        cout << "#" << test_case << " " << result << " " << SubTree(result) << "\n";

        for(int i=1; i<=V; i++){
            AL[i].clear();
        }

	}
	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}