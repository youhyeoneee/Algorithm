#include <iostream>

using namespace std;

int main(){

    int N, plus;

    cin >> N;

    int dp[N+1] = {0, };

    // 초기식
    dp[0] = 1; // 자기 개수일 경우 새로 생기는 고유한 문양 
    dp[2] = 3;

    for(int i=4; i<=N; i+=2){
        dp[i] = dp[i-2] * dp[2]; // 3 * dp[N-2]
        for(int j=4; j<=i; j+=2){
            dp[i] += dp[i-j] * 2; // 2*dp[N-4] + 2*dp[N-6] + .. + 2*dp[0]
        }
        
    }

    cout << dp[N] << endl;
    
    return 0;
}