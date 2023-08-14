#include<iostream>

using namespace std;

int main(){
    int A;
    
    cin >> A;

    int Ai[A+1] = {0,};

    for(int i=1; i<=A; i++) 
        cin >> Ai[i];

    long long dp[A+1] = {1, }; // 가장 긴 감소하는 부분 수열의 길이

    dp[1] = 1;
    
    for(int i=2; i<=A; i++){
        dp[i] = 1;
        for(int j=1; j<A; j++)
            if(Ai[j] > Ai[i]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
    }
    int result = 0;
    for(int i=1; i<=A; i++){
        if(result < dp[i])
            result = dp[i];
    }
    cout << result << endl;
    return 0;
}