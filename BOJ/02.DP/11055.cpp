#include <iostream>

using namespace std;

int main() {

    int A;

    cin >> A;

    int Ai[A+1] = {0,};
    
    for (int i=1; i<=A; i++)
        cin >> Ai[i];
    
    long long dp[A+1] = {0, }; //합이 가장 큰 증가 부분 수열의 합

    // 초기식 세팅
    dp[1] = Ai[1];

    for(int i=2; i<=A; i++){
        dp[i] = Ai[i];

        for(int j=1; j<A; j++){
            //자기 자신보다 작은 값들 중 합이 제일 큰 ...
            if(Ai[j] < Ai[i]){
                dp[i] = max(dp[j]+Ai[i], dp[i]);
            }
        }
    }

    int result = 0;
    for (int i=1; i<=A; i++){
        if (result < dp[i])
            result = dp[i];
    }

    cout << result << endl;
    return 0;
}