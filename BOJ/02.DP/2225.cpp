#include <iostream>
#include <string.h> 
#define MOD 1000000000
using namespace std;

int main(){

    int N, K;

    cin >> N >> K;

    long long dp[N+1][K+1] = {0, }; // 0부터 N까지 정수 K개를 더해 그 합이 N이 되는 경우
    memset(dp, 0, sizeof(dp));

    //dp[N][1] = 1
    for(int i=0; i<=N; i++)
        dp[i][1] = 1;

    //dp[0][K] = 1
    for (int i=1; i<=K; i++){
        dp[0][i] = 1;
    }

    //dp[N][K] = dp[N-i(i=0~N)][K-1]
    for(int i=1; i<=N; i++){
        for(int j=2; j<=K; j++){
            for(int k=0; k<=i; k++){
                dp[i][j] += dp[i-k][j-1];
            }
            dp[i][j] %= MOD;  
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}