#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int map[16][13];
int map_copy[16][13];
int result, N, W, H;
vector<int> shoot; // 중복 순열



void Copy(){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            map_copy[i][j] = map[i][j];
        }
    }
}

void Print(){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << map_copy[i][j] << " ";
        }
        cout << endl;
    }
}

// 남은 벽돌 개수 세기
int Count(){
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if (map_copy[i][j] > 0) cnt++;
        }
    }

   return cnt;
}


void Remove(int x, int y){

    int range = map_copy[x][y];

    map_copy[x][y] = 0;

    if (range > 1){
        // 상
        int up = -1; 
        for(int i=1; i<range; i++){
            if (x+up < 0) break;

            // 추가로 제거
            if (map_copy[x+up][y] > 1){
                Remove(x+up, y);
            }
            map_copy[x+up][y] = 0;
            up--;
        }

        // 하
        int down = 1; 
        for(int i=1; i<range; i++){
            if (x+down >= H) break;

            // 추가로 제거
            if (map_copy[x+down][y] > 1){
                Remove(x+down, y);
            }
            map_copy[x+down][y] = 0;
            down++;
        }

        // 좌
        int left = -1; 
        for(int i=1; i<range; i++){
            if (y+left < 0) break;

            // 추가로 제거
            if (map_copy[x][y+left] > 1){
                Remove(x, y+left);
            }
            map_copy[x][y+left] = 0;
            left--;
        }

        // 우
        int right = 1; 
        for(int i=1; i<range; i++){
            if (y+right >= W) break;

            // 추가로 제거
            if (map_copy[x][y+right] > 1){
                Remove(x, y+right);
            }
            map_copy[x][y+right] = 0;
            right++;
        }

    }
 
}

void Move(){

    // 모든 열을 체크
    for(int i=0; i<W; i++){

        vector<int> v;

        for(int j=0; j<H; j++){
            if (map_copy[j][i] > 0){
                v.push_back(map_copy[j][i]);
                map_copy[j][i] = 0;
            }
        }

        for(int j=0; j<v.size(); j++){
            
            // 앞에서부터 j = 0, 1, 2
            // 높이가 10이면 7, 8, 9 에 쌓아야 하므로
            // 0 -> 7 (0+10-3)
            // 1 -> 8 (1+10-3)
            // 2 -> 9 (2+10-3)
            // j -> j + H - v.size
            map_copy[j+H-v.size()][i] = v[j];
        }

    }
}
int Solution(){

    Copy(); // 맵 복사

    // N번 쏘기
    for(int cnt=0; cnt<N; cnt++){
        int x = 0, y = shoot[cnt];

        // 맨 위에 있는 벽돌 찾기
        for(x=0; x<H; x++){
            if(map_copy[x][y] > 0) break;
        }    

        // 제거
        Remove(x, y);

        // 떨어트리기
        Move();
    }

    return Count();
}


// 구슬 맞출 위치들을 중복 순열로 구하기
void Dfs(int cnt)
{
	if (cnt == N)
	{
		int ans = Solution();
		result = min(result, ans);
		return;
	}
	for (int i = 0; i < W; i++)
	{
		shoot.push_back(i);
		Dfs(cnt + 1);
		shoot.pop_back();
	}
}


void Init(){
    result = 15*12; // 최대 크기
    memset(map, 0, sizeof map);
}

void Input(){
   cin >> N >> W >> H;
   for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
        cin >> map[i][j];
    }
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