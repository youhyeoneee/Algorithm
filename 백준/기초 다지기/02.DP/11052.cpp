#include <iostream>
#include <string.h>

using namespace  std;

int main(){
    int N; // 민규가 구매하려고 하는 카드의 개수
    cin >> N;
    int P[N+1]; // 카드가 i개 포함된 카드팩의 가격 (i=1~N)
    memset(P, 0, sizeof(P)); // 0으로 초기화

    for (int i=1; i<=N; i++)   
        cin >> P[i];

    int dp[N+1]; // 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값 (i=1~N)
    memset(dp, 0, sizeof(dp)); // 0으로 초기화

    dp[1] = P[1]; // 카드 1개 사려 할 때

    for (int i=2; i<=N; i++){

        int result = P[i];
        for (int j=0; j<=i; j++){
            int temp = P[i-j] + dp[j]; // dp[N] = dp[N-i] + P[i] (i=0~N)
            if (result < temp)
                result = temp;
        }
        dp[i] = result;
    }
    cout << dp[N] << endl;

    return 0;
}