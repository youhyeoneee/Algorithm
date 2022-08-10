#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

using namespace std;

int AL[100][5]; // 1 ~ 99, 자식 최대 5개
bool visited[100];
int king;
int next_king;
bool find;

struct Stack
{
    
    public:
        int top();
        void pop();
        
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

void dfs_init(int N, int path[100][2])
{
    // 각 테스트케이스 시작 시 초기화를 위해 1번 호출된다.
    // Parameters
    // N : 인물 수 (2 ≤ N ≤ 40)
    // path[][] : 관계도

    for(int i=0; i<100; i++){
        visited[i] = false;
        for(int j=0; j<5; j++)
            AL[i][j] = 0;
    }

    for(int i=0; i<N; i++){
        int parent = path[i][0];
        int child = path[i][1];

        for(int j=0; j<5; j++){
            if (AL[parent][j] == 0) 
                AL[parent][j] = child;
        }
    }

    king = 0;
    find = false;

}

int dfs(int n)
{
    // 능력 n을 가지는 인물이 왕이 되었을 경우, 왕위를 계승할 인물의 능력을 반환한다.
    // 왕위를 계승할 인물이 없으면 -1을 반환한다.

    // Parameters
    // n : 능력 (1 ≤ n ≤ 99)
    

    visited[n] = true;

    // 찾았다면
    if (find) return next_king;
    if (king == 0) king = n;

    for(int next : AL[curr]){
        if (visited[next] == true)
            return -1;
        if (next > king){
            next_king = next;
            find = true;
            return next_king;
        }
        else
            dfs(next);
    }


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