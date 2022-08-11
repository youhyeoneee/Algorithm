#include <string.h> 
#include <iostream>
#include <vector>

using namespace std;


// 좌표 
struct Pos
{
    int x;
    int y;

    public:
        void setPos(int x1, int y1){
            x = x1;
            y = y1;
        }
};

vector<Pos> v; // 연결해야 할 셀들의 좌표 목록
int arr[12][12]; // 지도
int N; // 가로, 세로 길이 
int result; // 결과
int core; // 연결한 프로세서 개수

// 상하좌우 
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };


// 연결할 수 있는가
bool isLine(int x, int y, int i){
    int nx = x;
    int ny = y;

    while(true){
        nx += dx[i];
        ny += dy[i];

        // 막히지 않고 연결 성공
        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1) break;

        // 가다가 코어에 막히는 경우
        if (arr[nx][ny] != 0) {
            return false;
        }
    }

    return true;
}

// 선을 그리기
int drawLine(int x, int y, int i, int flag){
    int cnt = 0;
    int nx = x;
    int ny = y;
    
    while(true){
        nx += dx[i];
        ny += dy[i];

        // 막히지 않고 연결 성공
        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1)
            break;
        
        // flag = 0 : 그리기 / 1 : 지우기
        arr[nx][ny] = (flag == 0)? 2 : 0;
        cnt++;
    }

    return cnt;
}

void dfs(int idx, int num, int line){

    if (idx == v.size()){

        // cout << "idx" << num << "&" << result << '\n';
        //  최대한 많은 Core에 전원을 연결 
        if (num > core) {
            result = line;
            core = num;
        }

        // 전선 길이의 합이 최소가 되는 값으로 갱신
        else if (core == num){
            if (result > line) result = line;
        }
    }

    else{   
        // 연결될 수 있는지 체크
        int x = v[idx].x;
        int y = v[idx].y;

        for(int i=0; i<4; i++){
            // cout << "LINE : " << x <<"," << y << " = >";
            // cout << isLine(x, y, i) << "\n";
           if(isLine(x, y, i)){
                // cout << "POSSIBLE\n";
                // 4방향으로 선 그리는 경우 
                dfs(idx+1, num+1, line + drawLine(x, y, i, 0));
                drawLine(x, y, i, 1); // 선 삭제 
           }

        }

        // 연결하지 않는 경우
        dfs(idx+1, num, line);

    }
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;

        // 초기화
        memset(arr, -1, sizeof arr);
        result = 144; 
        core = 0;
        v.clear();

        //다음 N줄에 걸쳐서 멕시노스의 초기 상태가 N x N 배열로 주어진다.
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &arr[i][j]);
                // 0은 빈 cell을 의미하며, 1은 core를 의미하고, 그 외의 숫자는 주어지지 않는다.
                if (arr[i][j] == 1){
                    // 가장자리에 있어 이미 연결된 cell들
                    if ( i== 0 || i == N-1 || j == 0 || j == N-1)
                        continue;
                    else{
                        Pos p;
                        p.setPos(i, j);
                        v.push_back(p);
                    }
                }

            }
        }

        dfs(0, 0, 0);

        printf("#%d %d\n", test_case, result);
    }
	return 0;
}