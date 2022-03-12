#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;

    cin >> n; // 포도주 잔의 개수

    int a[n+1] = {0,};
    for (int i=1; i<=n; i++)
        cin >> a[i];


    long long dp[3][n+1]; // 경우의 수 i, n개의 포도잔일 경우 최대의 값
    
    // i=0 : 1번째 전 + 자신
    // i=1 : 2번째 전 + 자신
    // i=2 : 1번째 전 + 2번째 전 

    // 0 -> 2
    // 1 + 자신 -> 0
    // 2 + 자신 -> 1
    
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    // 1번째 잔과 2번째 잔의 경우는 직접 세팅해준다. 

    // 1번째 잔 (n=1)
    dp[0][1] = dp[1][1] = a[1]; // i=0 (1번째 전(0) + 자신), 1(2번째 전(0) + 자신) 
    dp[2][1] = 0; // i=2 (1번째 전(0) + 2번째 전(0))

    // 2번째 잔 (n=2)
    dp[0][2] = dp[1][1] + a[2]; // i=0 (1번째 전 + 자신)
    dp[1][2] = a[2]; // i=1 (2번째 전(0) + 자신) 
    dp[2][2] = dp[1][1]; // i=2 (1번째 전 + 2번째 전(0))
    

    for(int j=3; j<=n; j++){
        dp[0][j] = dp[1][j-1] + a[j];
        dp[1][j] = dp[2][j-1] + a[j];
        dp[2][j] = dp[0][j-1];
    }

    for (int i=0; i<=n; i++){
        for(int j=0; j<3; j++)
            cout << dp[j][i] << " ";
        cout << endl << "-------------------" << endl;
    }
    
    cout << max({dp[0][n], dp[1][n], dp[2][n]});

    return 0;
}