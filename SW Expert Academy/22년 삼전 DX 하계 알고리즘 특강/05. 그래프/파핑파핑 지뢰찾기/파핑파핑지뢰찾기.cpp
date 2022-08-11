#include <iostream>
#include <queue>
#include <string.h>

using namespace std;


int N; // 지뢰 찾기를 하는 표의 크기가 N*N
char arr[300][300];
bool visited[300][300]; // 지뢰 : -1
int result;

// 주위 8방향
int dx[] = {1, 1, 1, 
            -1, -1, -1, 
            0, 0};

int dy[] = {1, 0, -1, 
            1, 0, -1,
            1, -1,};

struct Pos
{
    int x;
    int y;

    public:
        void setPos(int i, int j){
            x = i;
            y = j;
        }
};

// 주변에 지뢰가 있는가 
bool isZero(int x, int y){

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) continue;
        // 주변에 지뢰가 있다
        if (arr[nx][ny] == '*') return false;
        
    }

    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{

        cin >> N;


        // INPUT
        // * : 지뢰가 있다 / . : 지뢰가 없다
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)  {
                cin >> arr[i][j];
            }   
        }

        // 방문 여부, 결과 초기화
        memset(visited, 0, sizeof visited);
        result = 0;

        // PROCESS
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                if (!visited[i][j] && arr[i][j] == '.'){
                    if (isZero(i, j)){ // 주변에 지뢰가 없다면(숫자가 0이면)
                        result++; // 클릭
                        Pos p;
                        p.setPos(i, j);

                        // bfs 할 큐 생성
                        queue<Pos> q;
                        q.push(p);

                        while(!q.empty()){
                            Pos curr = q.front();
                            int x = curr.x;
                            int y = curr.y;

                            visited[x][y] = true; // 방문 처리
                            q.pop();
                            
                            for(int k=0; k<8; k++){
                                int nx = x + dx[k];
                                int ny = y + dy[k];

                                // 범위 초과하거나, 방문했거나, 지뢰인곳
                                if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1 || visited[nx][ny] || arr[nx][ny] == '*') continue;
                                // 주변에 지뢰가 있다

                                visited[nx][ny] = true;
                                if (isZero(nx, ny)) {  // 주변에 지뢰가 없다면(숫자가 0이면)
                                    Pos p2;
                                    p2.setPos(nx, ny);
                                    q.push(p2);
                                }
                            }
                        }
                    }
                }
                
                
            }
        }


        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if (arr[i][j] == '.' && !visited[i][j]) result++;
            }
        }

        cout << "#" << test_case << " " << result << "\n";


	}
	return 0;
}