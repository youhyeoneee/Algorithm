// 외판원 순회 Core 코드

// [[[ Memoization DP ]]]

int D[16][1<<16]; // [i][j] 현재 상태에서의 최소비용 (i에 도착한 상태에서 방문 정보가 j일 때)

inline int MIN(int a, int b) { return a < b ? a : b; }

int dp(int curr, int visited) {
    if (!D[curr][visited]) {
        if (visited == ALLVISITED) {
            D[curr][visited] = AM[0][curr];
        }
        else {
            D[curr][visited] = 2000000;
            for (int next = 1; next < N; next++) {
                if (visited & (1 << next)) continue;
                D[curr][visited] = MIN(D[curr][visited], dp(next, visited | (1 << next)) + AM[next][curr]);
            }
        }
    }
    return D[curr][visited];
}

// in main function
// dp(0, 1) 호출

// [[[ Tabulation DP ]]]

// 현재 D[i][j] 상태일 경우
// 다음으로 진행할 경우를 가정하자.
for (int i = 0; i < N; i++) {
    for (int j = 1; j <= ALLVISITED; j++) {
        if (j & (1 << i)) {
            for (int k = 0; k < N; k++) {
                // j 의 상태가 이미 k 를 방문한 상태가 아닐 때만 아래 구문을 수행한다.
                if (j & (1 << k)) continue;
                if (D[k][j | (1 << k)] == 0) D[k][j | (1 << k)] = D[i][j] + W[i][k];
                else D[k][j | (1 << k)] = MIN(D[k][j | (1 << k)], D[i][j] + W[i][k]);
            }
        }
    }
}
// 위 코드는 완전하지 않을 수 있다.
// 체크해야 할 사항 : D[k][j|(1<<k)] 보다 D[i][j] 가 무조건 먼저 확정이 되어야 로직이 제대로 돌아감.

// Answer = 최소(D[1][ALLVISITED] + W[1][0], D[2][ALLVISITED] + W[2][0], ..., D[N - 1][ALLVISITED] + W[N - 1][0]);