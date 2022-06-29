#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    int N = 0;
    cin >>  N;
    int dp[N+1] = {0, };

    // 작은 값 바텀업 형식으로 
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + 1; // 1로 빼보고 일단 저장
        if(!(i%3)) dp[i] = min(dp[i], dp[i/3]+1); // 3으로 나눠지면 1로 뺀거랑 비교 해서 최솟값
        if(!(i%2)) dp[i] = min(dp[i], dp[i/2]+1); // 2으로 나눠지면 1로 뺀거랑 비교 해서 최솟값
    } 

    // 그렇게 N까지 반복해서 연산 결과 출력
    cout << dp[N] << endl;

    return 0;
}

