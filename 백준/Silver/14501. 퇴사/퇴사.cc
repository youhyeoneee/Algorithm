#include <iostream>
#include <algorithm>

#define MAX 1004
using namespace std;


void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(int &N, int T[], int P[]) {
    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> T[i] >> P[i];
    }
}

int solve(int &N, int T[], int P[]) {

    int dp[MAX];
    int deadLine;
	for (int i=N; i>0; i--){
		deadLine = i + T[i];
		if (deadLine > N+1){
			// 상담 불가
			dp[i] = dp[i+1];
		}
		else {
			// 상담 가능, 최대 이익 판별 필요
			dp[i] = max(dp[i+1], dp[deadLine] + P[i]);
		}
	}
    return dp[1];
}

void output(int answer) {
    cout << answer << "\n";
}

int main() {
    int N;
    int T[MAX], P[MAX];
    input(N, T, P);
    output(solve(N, T, P));
    

    return 0;
}
