#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>

using namespace std;

extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);

int graph[11][11]; // 지도
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 좌표
struct Pos{
    int x;
    int y;

	public:
		void set(int x1, int y1){		
			x = x1;
			y = y1;
		}
};

struct Queue
{   
	// (x,y), 거리
	Pos arr[101];
	int front, back;
    

    public:
		void init(){
			front = 0;
			back = 0;
		}

		void push(Pos pos){
			cout << "PUSH : " << pos.x << "," << pos.y << "\n";
			arr[back++] = pos; 
		}

		bool empty(){
			return back == 0;
		}

        Pos top(){
			if (empty()) {
				Pos p;
				p.x = -1;
				p.y = -1;
				return p;
			}
			return arr[front];
		}

        void pop(){
			if (!empty()) {
				for(int i=0; i<back-1; i++){
					arr[i] = arr[i+1];
				}
				back--;
			}
		}
		void print(){
			cout << "\nQUEUE\n";
			for(int i=0; i<back; i++){
				cout << arr[i].x << "," << arr[i].y << " ";
			}
			cout << "\n";
		}

};

void bfs_init(int map_size, int map[10][10]) {
// 행과 열의 크기가 map_size(1 <= map_size <= 10) 인 지도가 주어진다.
// 지도는 0-base인 배열로 표현되며 map[10][10] 으로 주어진다. 
// 배열의 각 값들은 0 또는 1이며 '0'은 길을, '1'은 벽을 의미한다.


	// 배열 초기화
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++)
			graph[i][j] = -1;
	}

	// 지도 저장
	cout << "MAP\n";
	for(int i=1; i<=map_size; i++){
		for(int j=1; j<=map_size; j++){
			graph[i][j] = map[i-1][j-1];
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	// 행, 열 크기 저장
	N = map_size;
 
}
int bfs(int x1, int y1, int x2, int y2) {

// 시작점 x1, y1 좌표가 주어지고 도착점 x2, y2가 주어지면 시작점에서 도착점까지 가는데 최단 거리로 갈 경우 몇 번을 이동하면 되는지 이동 횟수를 계산해서 return해야 한다.

// x는 열이고 y는 행임을 주의해야 한다. 그리고 좌상 좌표는 x=1, y=1 이다.

// 만약 만약 갈 수 있는 방법이 없을 경우 -1을 return해야 한다.

// 시작점과 도착점이 같은 경우는 없다.


	// 거리 배열 초기화
	int distance[11][11];

	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			distance[i][j] = -1;
		}
	}

	distance[y1][x1] = 0;

	// 큐 생성
	Queue q;
	q.init();

	// 시작점 
	Pos start;
	start.set(x1, y1);

	q.push(start);
	
	while(!q.empty()){
		q.print();
		Pos curr = q.top();
		q.pop();

		
		cout << "CURR : " << curr.x << "," << curr.y << "\n";

		if (curr.x == x2 && curr.y == y2){
			cout << "RESULT : " << distance[y2][x2] << "\n";
			return distance[y2][x2];
		}

		for(int i=0; i<4; i++){
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];

			if (nx > N || nx < 1 || ny > N || ny < 1 || graph[ny][nx] == 1)
				continue;
			if (distance[ny][nx] == -1)
			{
				distance[ny][nx] = distance[curr.y][curr.x] + 1;

				Pos p;
				p.set(nx, ny); 
				q.push(p);
			}
		}

	}

	cout << "RESULT : " << -1 << "\n";
    return -1;
}

static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) {
			cout << "WRONG ANSWER : " << result << '\n';
			score = 0;
		}
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);

	printf("#total score : %d\n", test_bfs());

	return 0;
}