// 동적계획법1 Core 코드 (가장큰정사각형, 행렬곱셈, LIS)

// [[[ 가장큰정사각형 ]]]

// 첫번째 행의 D 값을 초기값으로 저장
for (int j = 1; j <= M; j++) {
    D[1][j] = mat[1][j];
}
// 첫번째 열의 D 값도 저장
for (int i = 1; i <= N; i++) {
    D[i][1] = mat[i][1];
}

for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
        if (i == 1 || j == 1) continue;
        if (mat[i][j] == 0) D[i][j] = 0;
        else {
            // 바로 왼쪽 D[i][j-1], 바로 윗쪽 D[i-1][j] , 바로 왼쪽위의 대각선 D[i-1][j-1]
            // 이 세 가지 값 중 가장 작은 값에 의존될 수 밖에 없음.
            D[i][j] = mymin(mymin(D[i][j - 1], D[i - 1][j]), D[i - 1][j - 1]) + 1;
        }
    }
}

// [[[ 행렬곱셈 ]]]

// D[i][j] : i번째 행렬부터 j번째 행렬까지 곱했을때 필요한 '최소' 곱셈연산 수

// DP 테이블을 만드는 순서
// D[1][2], D[2][3], ...., D[N-1][N] step=1
// D[1][3], D[2][4], .., D[N-2][N]   step=2
// ...
// D[1][N] step=N-1

// ABCD : A(BCD), (AB)(CD), (ABC)D
for (int step = 1; step < N; step++) {
    for (int start = 1; start + step <= N; start++) {
        D[start][start + step] = INT_MAX;
        for (int mid = start; mid < start + step; mid++) {
            D[start][start + step] = mymin(D[start][start + step]
                , D[start][mid] + D[mid + 1][start + step] + Row[start] * Col[start + step] * Col[mid]);
        }
    }
}

// [[[ LIS ]]]

#include <cstdio>
#include <algorithm>
int N;

struct arr_t {
    int value;
    int index;
    inline bool operator<(const arr_t &ref) const {
        return this->value < ref.value;
    }
};

arr_t A[1000001], T[1000001];
int T_length;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i].value);
    }

    // processing
    for (int i = 1; i <= N; i++) {
        // arr_t 에 호환되도록 lower_bound 함수를 사용하여 해결해보세요
        arr_t *idx = std::lower_bound(T, T + T_length, A[i]);
        *idx = { A[i].value, i };
        if (idx == T) A[i].index = -1;
        else A[i].index = idx[-1].index;
    }

    // ...(중략)...

    return 0;
}

