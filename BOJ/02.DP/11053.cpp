#include <iostream>

using namespace std;

int main(){

    int A;
    cin >> A;
    int Ai[A+1] = {0,}; 

    for(int i=1; i<=A; i++)
        cin >> Ai[i];


    long long dp[A+1] = {1, }; // 증가하는 수열의 길이를 저장 (1보다 작을 수 없으므로 1로 초기화)

    // 초기식 
    dp[1] = 1;   

    for(int i=2; i<=A; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(Ai[j] < Ai[i]){ // 현재 값보다 작다면    
                dp[i] = max(dp[j]+1, dp[i]); // 작은 값들 중에 부분 수열 + 1 을 계속 갱신한다.
            }
        }
    }
    int result = 0;
    for (int i=1; i<=A; i++){
        if (dp[i] > result)
            result = dp[i];
    }
    cout << result << endl;

}