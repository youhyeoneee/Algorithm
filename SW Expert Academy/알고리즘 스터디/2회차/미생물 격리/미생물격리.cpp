#include <iostream>
#include <vector>
#include <string.h>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result, N = 101, M, K;

// 상: 1, 하: 2, 좌: 3, 우: 4
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

struct Microbe{
    int cnt; // 지도에서 미생물 개수
    int max_cnt; // 최대 개수 
    int direct; // 이동 방향
};

Microbe map[101][101];
Microbe new_map[101][101];

void Print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << map[i][j].cnt << " ";
        cout << endl;
    }
}

void Init(){
    result = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // 빈 미생물 배치
            Microbe m; 
            m.cnt = 0;
            m.max_cnt = 0;
            m.direct = 0;
            map[i][j] = m;
        }
    }
}

void Input(){
    int x, y;
    // 한 변에 있는 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K
    cin >> N >> M >> K;

    for(int i=0; i<K; i++){
       Microbe m;
       cin >> x >> y >> m.cnt >> m.direct;
       m.max_cnt = m.cnt;
       map[x][y] = m; // 지도에 미생물 배치
    }
}


// 방향 바꿔주는 함수
int ChangeDir(int dir){
    if(dir == 1) return 2;
    else if (dir == 2) return 1;
    else if (dir == 3) return 4;
    else if (dir == 4) return 3;

    return 0;
}

// 이동
void Move(){
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            // 미생물이 있는 경우
            if (map[x][y].cnt > 0){
                Microbe m = map[x][y];
                int nx = x + dx[m.direct];
                int ny = y + dy[m.direct];

                // 미생물 군집이 이동 후 약품이 칠해진 셀에 도착하면
                if (nx == 0 || nx == N-1 || ny == 0 || ny == N-1){
                    new_map[nx][ny].cnt = m.cnt/2; //  군집 내 미생물의 절반이 죽고
                    new_map[nx][ny].direct = ChangeDir(m.direct); // 이동방향이 반대로 바뀐다. 
                }   
                // 약품 아닌 셀에 도착하면
                else{
                    // 이미 미생물이 존재할 경우 (겹치는 경우)
                    if (new_map[nx][ny].cnt > 0){
                        // 추가
                        new_map[nx][ny].cnt += m.cnt;

                        // 더 큰 미생물이 오는 경우
                        if (new_map[nx][ny].max_cnt < m.cnt){
                            // 이동 방향 갱신 & max cnt 갱신
                            new_map[nx][ny].max_cnt = m.cnt;
                            new_map[nx][ny].direct = m.direct;
                        }
                    }
                    // 새로 도착한 미생물일 경우
                    else{
                        new_map[nx][ny].max_cnt = m.cnt;
                        new_map[nx][ny].cnt = m.cnt;
                        new_map[nx][ny].direct = m.direct;
                    }
                }
            }
        }
    }

    // new_map -> map 으로 이동해주기 & new_map 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = new_map[i][j];
            
            Microbe m; 
            m.cnt = 0;
            m.max_cnt = 0;
            m.direct = 0;
            new_map[i][j] = m;
        }
    }
}


void Solve(){

    // 이동 
    for(int i=0; i<M; i++){
        Move();
    }

    // 합산
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result += map[i][j].cnt;
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
		Init();
        Input();
        Solve();
        cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}