#include <iostream>
#define mod 1000000000

using namespace std;

int main(){

    int N;

    cin >> N;
    int dp[N+1][10] = {0, }; // 길이수, 끝자리 숫자

    // 1만큼 길이일때 9개  
    for (int i=1; i<=9; i++)
        dp[1][i] = 1;

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){  // j는 끝 자리 숫자
            if (j == 0){ // j = 0 이면 1->0 
                dp[i][j] = dp[i-1][j+1];
            }
            else if(j == 9){ // j = 9 면 8->9
                dp[i][j] = dp[i-1][j-1];
            }
            else{ // j = 1 ~ 8 이면 +-1 더하기 (ex. j=1 : 2->1, 0->1)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }

            dp[i][j] %= mod;
        } 
        
    }

    int sum = 0;
    for(int i=0; i<=9; i++)
        sum = (sum + dp[N][i]) % mod;

    cout << sum << endl;

    return 0;
}