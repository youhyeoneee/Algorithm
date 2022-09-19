#include <iostream>
#include <string.h>

using namespace std;

int highest, result, N, K; 
int arr[8][8];
bool visited[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, bool shaved, int length){
    
    // 답 갱신
    if (result < length) result = length;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도를 벗어나거나 이미 방문했을 경우 pass
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;

        // 방문 가능한 경우
        if (arr[nx][ny] < arr[x][y]){
            
            // 방문 처리
            visited[nx][ny] = true;
            // 재귀
            dfs(nx, ny, shaved, length + 1);
            // 방문 처리 해제
            visited[nx][ny] = false;

        }
        // 방문 불가능한 경우
        else{
            if (!shaved){   // 공사를 아직 안했을 때

                if (arr[nx][ny] - K < arr[x][y]){ // 공사 하면 가능한 경우
                    // 방문 & 공사 처리
                    visited[nx][ny] = true;
                    int origin = arr[nx][ny]; // 원래 값 저장
                    arr[nx][ny] = arr[x][y] - 1; // 공사해주기

                    // 재귀 (공사 여부 = true)
                    dfs(nx, ny, true, length + 1);

                    // 방문  & 공사 처리 해제
                    visited[nx][ny] = false;
                    arr[nx][ny] = origin;
                }
            }

        }
    }

}

int main(int argc, char** argv)
{
	int test_case;
	int T;


	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // INIT
        result = 0;
        highest = 0;
        memset(arr, 0, sizeof arr);
        memset(visited, false, sizeof visited);

        // INPUT 
        cin >> N >> K; // 지도의 한 변의 길이 N, 최대 공사 가능 깊이 K

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
                if (highest < arr[i][j]) highest = arr[i][j]; // 가장 높은 봉우리 저장
            }
        }

        // PROCESS
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if (arr[i][j] == highest){ // 가장 높은 봉우리에서만 시작
        
                    // 방문 처리 
                    visited[i][j] = true;

                    // 탐색 시작 (위치, 공사 여부, 등산로 길이)
                    dfs(i, j, false, 1);

                    // 방문 처리 해제 
                    visited[i][j] = false;

                }
            }
        }

		// OUTPUT 
        cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}