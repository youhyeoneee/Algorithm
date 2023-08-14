#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N, big, cnt = 0;
    cin >> N;
    int dp[N+1] = {0, };
    int sqrtArr[N+1]; // 1, 4, .. 제곱수들 모음
    dp[1] = 1;
    sqrtArr[cnt] = 1;

    for(int i=2; i<=N; i++){
        big = int(sqrt(i));
        if (sqrt(i)-big == 0){ // 제곱수일경우
            cnt++;
            sqrtArr[cnt] = i;
            dp[i] = 1;
        }
        else{
            dp[i] = 1 + dp[i - int(pow(big, 2))]; // 제일 큰 제곱수로 빼보고
            for(int j=cnt-1; j>=0; j--){
                int result = 1 + dp[i - sqrtArr[j]];
                if (dp[i] > result)
                    dp[i] = result;
            }

        }
    }
    cout << dp[N] << endl;    
    return 0;
}