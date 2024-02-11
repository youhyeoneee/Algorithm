#include <iostream>

#define MAX 1004
using namespace std;



void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(int &N, int P[]) {
    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> P[i];
    }
}

int solve(int &N, int P[]) {
    int dp[N+1];

    for(int i=1; i<=N; i++) {
        dp[i] = P[i];
    } 
    
    for(int i=2; i<=N; i++) {
        int end = (i%2 == 0)? i/2 : (i+2)/2; 
        for(int j=1; j<=end; j++) {
            dp[i] = max(dp[j] + dp[i-j], dp[i]);
        }
    }

    return dp[N];
}

void output(int answer) {
    cout << answer << "\n";
}

int main() {

    int N;
    int P[MAX];
    input(N, P);
    output(solve(N, P));

    return 0;
}