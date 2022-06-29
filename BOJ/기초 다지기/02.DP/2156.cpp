#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;

    cin >> n; // 포도주 잔의 개수

    int a[n+1] = {0,};
    for (int i=1; i<=n; i++)
        cin >> a[i]; // 각 포도주의 양


    long long dp[n+1]; // n개의 잔을 마셨을 경우 최대의 값
    
    

    // 1번째 잔과 2번째 잔의 경우는 직접 세팅해준다. 

    dp[0] = 0; 
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for (int i=3; i<=n; i++){

        // N번째 와인잔을 선택했을 때 마실 수 있는 경우의 수
        // 1. N-3번째까지의 최댓값 + N-1번째 잔 + N번째 잔 _] _ㅁ ㅁ
        // 2. N-2번째까지의 최댓값 + N번째 잔 _ _] _ ㅁ
        // 3. N-1번째까지의 최댓값(N선택 X) _ _] _ 

        dp[i] = max({dp[i-3]+a[i-1]+a[i], dp[i-2]+a[i], dp[i-1]});
    }

    cout << dp[n] << endl;
    

    return 0;
}