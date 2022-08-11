#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

int child_list[100][5]; // 인접리스트 1 ~ 99, 자식 최대 5개
int child_cnt[100]; // 자식 수
bool visited[100]; // 방문 여부 체크

struct Stack
{   
	int arr[40];
	int size;
    
    public:
		void init(){
			size = 0;
		}

		void push(int x){
			arr[size++] = x; 
		}

		bool empty(){
			return size == 0;
		}

        int top(){
			if (empty()) return -1;
			return arr[size-1];
		}

        void pop(){
			if (!empty()) size--;
		}
		void print(){
			cout << "STACK\n";
			for(int i=0; i<size; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}

};

static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

extern void dfs_init(int N, int path[MAX_N][2]);
extern int dfs(int k);

static int p[MAX_K+2];
static int c[MAX_K+2];
static int path[MAX_N][2];
static void makeTree(int n) {
	for (int i = 1; i < MAX_K+2; ++i) {
		p[i] = c[i] = -1;
	}
	c[pseudo_rand(MAX_K + 1) + 1] = 0;
	for (int i = 0; i < n; ++i) {
		int pi = pseudo_rand(MAX_K + 1) + 1;
		while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
			++pi;
			if (pi == MAX_K + 2)
				pi = 1;
		}
		int ci = pseudo_rand(MAX_K + 1) + 1;
		while (c[ci] >= 0) {
			++ci;
			if (ci == MAX_K + 2)
				ci = 1;
		}
		p[ci] = pi;
		++c[pi];
		c[ci] = 0;
	}
	bool check[MAX_K + 2] = { false };
	for (int i = 0; i < n; ++i) {
		int e = pseudo_rand(MAX_K + 1) + 1;
		while (check[e] || c[e] < 0 || p[e] == -1) {
			++e;
			if (e == MAX_K + 2)
				e = 1;
		}
		check[e] = true;
		path[i][0] = p[e];
		path[i][1] = e;
	}
}

void print(){

	cout << ">> CHILD LIST\n ";

	for(int i=1; i<100; i++){
		cout << "PARENT : " << i << " - ";	
		for(int j=0; j<5; j++){
			if (child_list[i][j] != 0) cout << child_list[i][j] << ",";
		}
		cout << "\n";
	}

}

void dfs_init(int N, int path[100][2])
{
    // 각 테스트케이스 시작 시 초기화를 위해 1번 호출된다.
    // Parameters
    // N : 인물 수 (2 ≤ N ≤ 40)
    // path[][] : 관계도

    for(int i=0; i<100; i++){
        visited[i] = false; // 방문여부 초기화
		child_cnt[i] = 0; // 자식 수 초기화
        for(int j=0; j<5; j++)
            child_list[i][j] = 0; // 자식리스트 초기화
    }

    for(int i=0; i<N-1; i++){
        int parent = path[i][0];
        int child = path[i][1];

        child_list[parent][child_cnt[parent]++] = child;
		cout << parent << "," << child << "\n";

    }

	print();
}

int dfs(int n)
{
    // 능력 n을 가지는 인물이 왕이 되었을 경우, 왕위를 계승할 인물의 능력을 반환한다.
    // 왕위를 계승할 인물이 없으면 -1을 반환한다.

    // Parameters
    // n : 능력 (1 ≤ n ≤ 99)
    
	for(int i=0; i<100; i++)
        visited[i] = false; // 방문 초기화

	// 스택 생성
	Stack s;
	s.init();
	s.push(n);

	cout << "FIND NEXT KING " << n << "\n";

	while(!s.empty()){
		int curr = s.top();
		s.pop();

		s.print();

		if (!visited[curr]){
			visited[curr] = true; // 방문 처리

			if(curr > n) {
				cout << "\n>> NEXT KING IS =" << curr << "\n";
				return curr;
			}

			for(int i=child_cnt[curr]-1; i>=0; i--){
				int next = child_list[curr][i];
				cout << next << "\n";
				if(!visited[next]){  // 방문하지 않은 자식들을 만나면 
					s.push(next);
				} 
			}
		}

		
	}
	

	cout << "\n>> NEXT KING IS = " <<  -1 << "\n";

	return -1;
}


int main() {
	setbuf(stdout, NULL);
	int T;
	//freopen("dfs_input.txt", "r", stdin);
	scanf("%d", &T);

	int totalScore = 0;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;

		scanf("%d %d %d", &n, &q, &seed);

		makeTree(n - 1);
		dfs_init(n, path);

		bool check[MAX_K + 2] = { false };
		int score = 100;
		for (int i = 0; i < q; ++i) {
			int k, ret, correct;

			scanf("%d", &k);

			ret = dfs(k);

			scanf("%d", &correct);

			if (ret != correct)
				score = 0;
		}
		printf("#%d : %d\n", tc, score);
		totalScore += score;
	}
	printf("#total score : %d\n", totalScore / T);

	return 0;
}