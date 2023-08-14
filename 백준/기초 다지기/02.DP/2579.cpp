#include <iostream>
#include <algorithm>

using namespace std;


// 반례 
// 142 = 3 (5^2 + 6^2 + 9^2)
// 41 = 2 (4^2 + 5^2)

int main(){
    int n, a, b, c; 

    cin >> n;

    int stair[n+1] = {0,};

    for(int i=1; i<=n; i++){
        cin >> stair[i];
    }

    int dp[n+1] = {0,};

    dp[0] = 0; // 시작점
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];


    for(int i=3; i<=n; i++){

        a = dp[i-2]+stair[i];
        b = dp[i-3]+stair[i-1]+stair[i];

        dp[i] = max(a, b);
        
    }

    cout << dp[n] << endl;

    return 0;
}