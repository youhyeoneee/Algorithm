#include <iostream>
#define MOD 10007

using namespace std;

int main(){

    int N, result = 0;
    
    cin >> N;

    int dp[N+1][10] = {0, }; // 수의 길이, 끝자리 수 

    for(int i=0; i<=9; i++) // 길이가 1이면 각 1개씩 가능
        dp[1][i] = 1;

    for (int i=2; i<=N; i++){
        for (int j=0; j<=9; j++){ // ex. j=1이면 이전 N-1줄의 0, 1을 합산
            int temp = 0;
            for(int k=0; k<=j; k++)
                temp += dp[i-1][k];
            dp[i][j] = temp % MOD;
        }
           
    }   


    for (int i=0; i<=9; i++)    
        result += dp[N][i];

    cout << result%MOD << endl;

    return 0;
}