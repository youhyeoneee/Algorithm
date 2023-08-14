#include <iostream>

using namespace std;

int dp[12] = {0,};

int main(){
    int T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> T; // 테스트 케이스

    for (int i=0; i<T; i++){
        int n;
        cin >> n;

        for(int j=4; j<=n; j++){
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }

        cout << dp[n] << endl;
    }

    return 0;

}