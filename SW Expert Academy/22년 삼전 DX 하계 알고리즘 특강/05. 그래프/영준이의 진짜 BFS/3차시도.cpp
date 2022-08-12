#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 100001
using namespace std;

// 15/61 오답

int N;
long long result;

vector<int> child_list[MAX]; // 자식
int parent[15][MAX]; // 부모 // [k][v] : 현재 정점 v에서 2의 k제곱번째 부모의 정점 번호를 저장
int depth[MAX]; // 깊이


long long LCA(int a, int b){

    long long res = 0;
    // 1. depth 맞추기(항상 a의 depth가 크도록 함)
    if (depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int diff = depth[a] - depth[b];
    for(int r=0; diff; r++){ // r : 자릿수 / diff가 0이 되는 순간 빠져나옴 
        // diff가 10이면 2^3 + 2^1 => 2진수로 표현하면 1010
        result++;
        if(diff & 1){ // 비트연산 & : 0이 아니면
            a = parent[r][a]; // 점프하기 
        }
        diff >>= 1; // 한 칸 내려주기 
    }

    long long res2 = 0;
    
    // 2. LCA 찾기
    while(a != b){
        int r;
        for(r=0; r<15; r++){
            res2++;
            if(parent[r][a] == parent[r][b]) break;
        }
        a = parent[r][a]; b = parent[r][b];
    }
    return res + (res2*2);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;

        // INIT 
        result = 0;
        depth[1] = 0;

        int p;
        // INPUT
        for(int c=2; c<=N; c++){
            cin >> p;

            child_list[p].push_back(c);
            depth[c] = depth[p] + 1;  // 자식 노드이므로 +1
            parent[0][c] = p;  // 부모 노드 등록
        }

        // PROCESS

        // 점핑 테이블(최소 테이블)을 만들기
        for(int r=1; r<15; r++){
            for(int i=1; i<=N; i++){
                parent[r][i] = parent[r-1][parent[r-1][i]]; // parent[r][i] = parent[r-1][i]의 2^(r-1) 번째 부모
            }
        }

        queue<int> q;
        q.push(1);

        int curr = 1, before = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            // 거리 찾기 solution
            result += LCA(before, curr); 
            before = curr;
            for(int next : child_list[curr]){
                q.push(next);
            }
        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

        // INIT
        memset(parent, 0, sizeof parent);
        memset(depth, -1, sizeof depth);
        for(int i=1; i<=N; i++){
            child_list[i].clear();
        }
	}
	return 0;
}