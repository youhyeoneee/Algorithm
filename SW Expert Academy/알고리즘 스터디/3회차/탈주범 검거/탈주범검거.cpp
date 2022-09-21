#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
#define DEBUG(X) // cout << X << "\n";

using namespace std;

int map[51][51]; // 숫자 1 ~ 7은 해당 위치의 터널 구조물 타입을 의미하며 숫자 0 은 터널이 없는 장소
bool visited[51][51];

int result;
int N, M; // 지하 터널 지도의 세로 크기 N, 가로 크기 M
int R, C; // 맨홀 뚜껑의 세로 위치 R, 가로 위치 C
int L; // 소요 시간

// 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


// 터널 모양에 따른 현재 위치에서 갈 수 있는 방향
vector<int> next_dir[7] = {
    {0, 1, 2, 3}, // 1번 모양 터널 -> 상, 하, 좌, 우
    {0, 1}, // 2번 모양 터널 -> 상, 하
    {2, 3}, 
    {0, 3},
    {1, 3},
    {1, 2},
    {0, 2}
};

// 다음 터널과 지금 터널이 이어질 수 있는 터널 모양들
int connected[4][4] = {
    {1, 2, 5, 6},
    {1, 2, 4, 7},
    {1, 3, 4, 5},
    {1, 3, 6, 7}
};

void Init(){
    result = 0;
    memset(map, 0, sizeof map);
    memset(visited, 0, sizeof visited);
}

void Input(){
   cin >> N >> M >> R >> C >> L;
   for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
        cin >> map[i][j];
    }
   }
}


// 터널이 지금 위치와 이어지는지
bool Find(int tunnel, int dir){ 
    int x = sizeof(connected[dir]) / sizeof(*connected[dir]);
    return find(connected[dir], connected[dir]+x, tunnel) != connected[dir]+x;
}


void Bfs(int time){
    queue<pair<int, int>> q; 
    q.push({R, C});
    visited[R][C] = true; // 방문 처리
    result = 1;

    while(!q.empty()){
        
        int size = q.size();
        while(size--){
            pair<int, int> curr = q.front();
            q.pop();

            // 현재 터널의 정보
            int x = curr.first;
            int y = curr.second;
            int shape = map[x][y]; 

            // 현재 터널에서 갈 수 있는 방향만 탐색
            for(int i : next_dir[shape-1]){
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 범위 벗어나거나 터널이 없는 경우 혹은 이미 방문한 경우 
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || !map[nx][ny] || visited[nx][ny]) continue;
                else{ 
                    if (Find(map[nx][ny], i)){ // 지금 위치 와 터널이 이어지는지
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        result++;
                        DEBUG(nx << "," << ny);
                    }
                }
            }
        }
        time++;

        if(time == L) break;
    }
}

void Solve(){
    pair<int, int> p = {R, C};

    if (L == 1) result = 1;
    else Bfs(1);
}


int main(int argc, char** argv)
{

    // 시간 줄이기
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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