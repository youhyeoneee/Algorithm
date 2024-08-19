#include <iostream>

using namespace std;

int dp[24];

int n;

int main() {
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }   

    cout << dp[n];

    return 0;
}