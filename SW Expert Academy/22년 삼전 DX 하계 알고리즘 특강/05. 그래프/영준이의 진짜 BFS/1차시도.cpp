#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 100001
using namespace std;

// Memory Limit Exceeded

int N;
int result;

vector<int> child_list[MAX]; // 자식
int parent[MAX]; // 부모
int depth[MAX]; // 깊이
int dist[MAX][MAX]; // 거리

void setDistance(int s, int e, int distance){
    dist[s][e] = distance;
    dist[e][s] = distance;
}

// depth s < depth e 라고 가정
pair<int, int> makeSameDepth(int s, int e){

    int cnt = 0;

    while(depth[s] != depth[e]){
        e = parent[e];
        cnt++;
    }

    // 맞춰진 깊이의 b와 맞춰지는데 들은 거리
    return {e, cnt};
}   


int findDistance(int s, int e){
    if (s != 1 || e != 1){
        // 거리가 안재져 있을 때
        if (dist[s][e] == 0){
            int a = s;
            int b = e;
            int cnt = 0;
            // 깊이 다를 때 깊이 맞춰주기
            if (depth[s] != depth[e]){
                pair<int, int> p = makeSameDepth(s, e);
                b = p.first; 
                cnt = p.second;
            }


            int cnt2 = 0;
            while(a != b){
                a = parent[a];
                b = parent[b];
                cnt2++;
            }
            setDistance(s, e, cnt+cnt2*2);
        }
    }

    return dist[s][e];
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
        memset(dist, 0, sizeof dist);

        int p;
        // INPUT
        for(int c=2; c<=N; c++){
            cin >> p;

            child_list[p].push_back(c);
            parent[c] = p;
            depth[c] = depth[p] + 1;

            // 부모와 자식의 거리는 1
            setDistance(p, c, 1);

            // 1 과 c 사이의 거리
            setDistance(1, c, depth[c]);
        }



        // PROCESS
        queue<int> q;
        q.push(1);

        int curr = 1, before = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            // 거리 찾기 solution
            result += findDistance(before, curr);

            before = curr;
            for(int next : child_list[curr]){
                q.push(next);
            }
        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

        // INIT
        memset(parent, 0, sizeof parent);
        memset(depth, 0, sizeof depth);
        for(int i=1; i<=N; i++){
            child_list[i].clear();
        }
	}
	return 0;
}