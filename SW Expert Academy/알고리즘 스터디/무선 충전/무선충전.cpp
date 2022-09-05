#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

struct User
{
    int x;
    int y;
    int sum;
};

struct BC
{
    int x; 
    int y;
    int C; // 거리
    int P; // 성능
};


long long result;
int M, A;
int map[11][11]; // 지도의 가로, 세로 크기는 10이다.
int moved[2][101]; // A, B 시간당 이동 내역
User userA, userB;
BC bc_list[8]; // BC의 개수 A는 1이상 8이하의 정수이다. (1 ≤ A ≤ 8)


// 이동하지 않음, 상 (UP), 우 (RIGHT), 하 (DOWN), 좌 (LEFT)
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};


// 방향에 따라 사용자 이동시킴 
void move_user(User &u, int dir){
    u.x = u.x + dx[dir];
    u.y = u.y + dy[dir];
}

// 두 BC가 같은 지 비교
bool compareBC(BC bc1, BC bc2){
    if (bc1.x == bc2.x && bc1.y == bc2.y) return true;
    return false;
}

// 최대 성능을 가진 BC 찾기
int findMaxBC(vector<BC> vector_bc){
    int max_bc = 0;
    for(int i=0; i<vector_bc.size(); i++){
        if (max_bc < vector_bc[i].P) max_bc = vector_bc[i].P;
    }

    return max_bc;
}

// BC 범위 내에 사용자가 있는지 체크
void check(){

    int max_bc = 0;
    vector<BC> vector_a, vector_b;

    for(int i=0; i<A; i++){
        BC bc = bc_list[i];
        int dist_a = abs(userA.x - bc.x) + abs(userA.y - bc.y);
        int dist_b = abs(userB.x - bc.x) + abs(userB.y - bc.y);

        // 각 범위 내에 있는 BC 리스트
        if(dist_a <= bc.C) vector_a.push_back(bc);
        if(dist_b <= bc.C) vector_b.push_back(bc);
    }

    // 겹치지 않는 경우 (둘 중 하나가 범위 내에 없는 경우)
    if (vector_a.size() == 0 || vector_b.size() == 0) {
        if (vector_a.size() == 0) max_bc = findMaxBC(vector_b);
        else if (vector_b.size() == 0) max_bc = findMaxBC(vector_a);
    }
    // 겹칠 수 있는 경우
    else {
        for (BC bc_a : vector_a) {
                for (BC bc_b : vector_b) {
                    int temp;
                    if (compareBC(bc_a, bc_b)) temp = bc_a.P; // 겹치는 경우
                    else temp = bc_a.P + bc_b.P; // 겹치지 않는 경우

                    // 최댓값 갱신
                    if (max_bc < temp) max_bc = temp;
                }
            }
    }

    result += max_bc;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   

        // INPUT
        cin >> M >> A; // 총 이동 시간(M), BC의 개수(A)

        // 사용자 A, B의 이동 정보
        for(int i=0; i<2; i++){
            for(int j=0; j<M; j++){
                cin >> moved[i][j];
            }
        }


        // AP 정보 (x, y), C(거리), P(성능)
        for(int i=0; i<A; i++){
            BC bc;
            cin >> bc_list[i].y >> bc_list[i].x >> bc_list[i].C >> bc_list[i].P;
            
        }

        // INIT 
        result = 0;


        // 사용자A는 지도의 (1, 1) 지점에서, 사용자B는 지도의 (10, 10) 지점에서 출발한다.
        userA.x = 1; userA.y = 1;
        userB.x = 10; userB.y = 10; 

        // PROCESS
        check(); // 처음 자리에서 더해주기

        for(int i=0; i<M; i++){ // 이동 시간에 따라 이동
            move_user(userA, moved[0][i]);
            move_user(userB, moved[1][i]);
            check();
        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

		
	}
	return 0;
}