#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <deque>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result, N, person_cnt, stair_cnt; 
int map[10][10];
bool visited[10];

struct Person {
    //위치
    int x, y;
    //선택된 계단(0 or 1) 
    int stair_idx;
    //선택된 계단 과의 거리
    int distance;
};
 
struct Stair {
    //위치
    int x, y;
    //계단 길이
    int length;
};

Person person[10];
Stair stair[2];

void Init(){
    result = 0;
    person_cnt = 0; // 사람 수
    stair_cnt = 0; // 계단 수
}

void Input(){
   cin >> N;
   for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        cin >> map[i][j];

        // 사람 정보 저장
        if (map[i][j] == 1) {
            Person p;
            p.x = i;
            p.y = j;
            person[person_cnt++] = p;
        }
        // 계단 정보 저장
        else if (map[i][j] >= 2) {
            Stair s;
            s.x = i;
            s.y = j;
            s.length = map[i][j];
            stair[stair_cnt++] = s;
        }
    }
   }
}

// p 사람이 s 계단으로 가는 거리
int GetDist(int p, int s){
    int dx = abs(person[p].x - stair[s].x);
    int dy = abs(person[p].y - stair[s].y);

    return dx + dy;
}

// 계산
void Calculate(){
    int time = 0;
    memset(visited, false, sizeof visited); // 초기화
    deque<int> dq[2];

    // 시간 계산
    while(true){
        // 모두 방문했는지 체크
        bool all_visited = true;
        for (int i = 0; i < person_cnt; i++) {
            if (!visited[i]) all_visited = false; // 하나라도 방문하지 못했다면 false
        }

        //모든 사람이 계단 안에 들어갔고 두 계단에 사람이 없을 경우 종료
        if (all_visited && dq[0].empty() && dq[1].empty()) break;
        
        //각각 사람 탐색
        for (int i = 0; i < person_cnt; i++) {
            //계단에 이미 들어간 사람일 경우, continue
            if (visited[i]) {
                continue;
            }

            // 계단에 도착하였을 시, 계단 deque에 계단 길이 넣어주기
            if (person[i].distance == time) {
                int now_stair = person[i].stair_idx;
                dq[now_stair].push_back(stair[now_stair].length);
                visited[i] = true;
            }
        }

        //2개 계단 모두 탐색
        for (int i = 0; i < stair_cnt; i++) {
            //계단에 사람이 있다면
            if (!dq[i].empty()) {
                //계단 deque에 사람이 3명 초과할 경우
                if (dq[i].size() > 3) {
                    //앞의 3명만 움직이기
                    for (int j = 0; j < 3; j++) {
                        dq[i][j]--; // 계단 길이 줄여줌
                    }
                }
                //계단 deque에 사람이 3명 이하일 경우
                else {
                    //계단에 있는 사람 전부 움직이기
                    for (int j = 0; j < dq[i].size(); j++) {
                        dq[i][j]--; // 계단 길이 줄여줌
                    }
                }

                for (int j = 0; j < dq[i].size(); j++) {
                    //계단을 다 내려간 사람이 있을 경우
                    if (dq[i][j] == 0) {
                        //계단 deque에서 제거
                        dq[i].pop_front();

                        //index 맞춰주기
                        j--;
                    }
                }
            }
        }

        //시간 증가
        time++;
    }

    // 최솟값 갱신
    if (result == 0 || time < result) result = time;   
}

void Dfs(int cnt){
    // 모두가 계단을 다 정했다면
    if (cnt == person_cnt){
        Calculate(); // 계산
        return;
    }

    //각 사람마다 0번 계단 또는 1번 계단 선택
    for(int i=0; i<stair_cnt; i++){
        // 계단 선택
        person[cnt].stair_idx = i;
        // 계단 과의 거리 저장
        person[cnt].distance = GetDist(cnt, i) + 1;
        Dfs(cnt+1);
    }
}

void Solve(){
   Dfs(0);
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