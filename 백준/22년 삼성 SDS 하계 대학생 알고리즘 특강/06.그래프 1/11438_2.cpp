#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

// LCA 2
using namespace std;


int N, M, a, b;

vector<int> AL[100001]; // 인접 리스트
int depth[100001]; // 깊이 저장
int parent[18][100001]; // [k][v] : 현재 정점 v에서 2의 k제곱번째 부모의 정점 번호를 저장
// 100000 < 2^17 : 0~17

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


int main(){ 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;  // 노드의 개수 N


    // 트리 상에서 연결된 두 정점
    for(int i=1; i<N; i++){
        cin >> a >> b;

        // 방향성이 없으므로 두 정점 다 인접리스트에 등록
        AL[a].push_back(b);
        AL[b].push_back(a);

    }

    // 전역변수로 정의된 배열을 모두 -이나 -1로 초기화 하는 방법
    memset(parent, 0, sizeof parent);
    // BFS를 이용하여 Depth 구현.
    for(int i=1; i<=N; i++) depth[i] = -1;  // depth -1로 모두 초기화

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

    for(int r=1; r<18; r++){
        for(int i=1; i<=N; i++){
            parent[r][i] = parent[r-1][parent[r-1][i]]; // parent[r][i] = parent[r-1][i]의 2^(r-1) 번째 부모
        }
    }

    cin >> M; // 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M

    // 정점 쌍
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }


    return 0;
}