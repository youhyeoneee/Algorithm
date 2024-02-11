#include <iostream>
#include <algorithm>

#define MAX 100004
using namespace std;


void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(int &n, int stickers[][MAX]) {
    cin >> n;

    for(int i=0; i<2; i++) {
        for(int j=1; j<=n; j++) {
            cin >> stickers[i][j];
        }
    }
}

int solve(int &n, int stickers[][MAX]) {
    int dp[2][n+1];
    
    dp[0][0] = 0;
    dp[1][0] = 0;

    dp[0][1] = stickers[0][1];
    dp[1][1] = stickers[1][1];

    for(int i=2; i<=n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stickers[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stickers[1][i];
    }

    return max(dp[0][n], dp[1][n]);
}

void output(int answer) {
    cout << answer << "\n";
}

int main() {
    int T;
    cin >> T; 
    for (int tc=0; tc<T; tc++) {
        int n;
        int stickers[2][MAX];
        input(n, stickers);
        output(solve(n, stickers));
    }


    return 0;
}