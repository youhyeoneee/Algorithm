#include <iostream>

using namespace std;

int main(){
    int N;

    cin >> N;

    long long dp[N+1][2] = {0, }; //숫자 길이와 끝자리 수 (0,1)

    dp[1][0] = 0; // 0으로 시작하지 않는다. 
    dp[1][1] = 1;
    
    for (int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1] << endl;

    return 0;
}