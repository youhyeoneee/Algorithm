#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result, N, M, C;
int map[10][10];
bool visited[10][10];
vector<vector<int>> honey;

void Init(){
    result = 0;
    memset(visited, false, sizeof visited);
    honey.clear();
}

void Input(){
    cin >> N >> M >> C;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
}

int Calc(int num, int idx, int sum, int ans){
    if (sum > C) return 0;  // 선택한 꿀의 양이 C보다 크면 의미 없는 조합
    if (idx == M) return ans; // 계산 완료

    int pow_data = honey[num][idx] * honey[num][idx];

    // 현재 위치 꿀을 채취할 경우
    int selected = Calc(num, idx+1, sum + honey[num][idx], ans + pow_data);
    // 현재 위치 꿀을 채취하지 않고 넘어가는 경우
    int not_selected =  Calc(num, idx+1, sum, ans);

    return max(selected, not_selected);
}

void Dfs(int start, int cnt){

    // 두 명의 일꾼이 모두 벌통을 선택했다
    if (cnt == 2){

        int result1 = Calc(0, 0, 0, 0);
        int result2 = Calc(1, 0, 0, 0);

        result = max(result, result1+ result2);
        return;
    }

    // 
    for(int i=start; i<N; i++){
        for(int j=0; j<N; j++){
            
            // 범위 초과
            if(j+M > N) continue;

            // 이미 방문했다면 pass
            bool check = false;
            for(int k=j; k<j+M; k++){
                if (visited[i][k]) {
                    check = true;
                    break;
                }
            }

            if (check) continue;

            // 방문 처리 & 꿀 벡터 저장 
            vector<int> v;
            for(int k=j; k<j+M; k++){
                visited[i][k] = true;
                v.push_back(map[i][k]);
            }

            honey.push_back(v);

            Dfs(i, cnt+1); // 2번 일꾼 선택

            honey.pop_back();
            for(int k=j; k<j+M; k++){
                visited[i][k] = false;
            }
        }
    }

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