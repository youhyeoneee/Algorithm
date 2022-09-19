#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <algorithm>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result;
int N; // 식재료의 수 
int S[16][16]; // 시너지 Sij값
bool visited[16];

void Init(){
    result = 20001; // 시너지의 최댓값이 20000
    memset(visited, 0, sizeof visited);
}

void Input(){
   cin >> N;
   for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> S[i][j];
   }
}

void Dfs(int cnt, int idx){

    // 재료를 반으로 나누었을 때
    if (cnt == N/2){
        int A = 0, B = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // 방문한 재료들은 A 
                if (visited[i] && visited[j])
                    A += S[i][j];
                // 방문하지 않은 재료들은 B
                else if (!visited[i] && !visited[j])
                    B += S[i][j];
            }
        }

        // 최솟값 갱신
        result = min(result, abs(A-B));
        return;
    }

    if (idx >= N || result == 0)
        return;

    // 조합 구현
    visited[idx] = true;
    Dfs(cnt + 1, idx + 1);
    visited[idx] = false;
    Dfs(cnt, idx + 1);

}

void Solve(){
    Dfs(0, 0);   
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		Init();
        Input();
        Solve();
        cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}