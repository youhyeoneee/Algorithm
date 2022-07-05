#include <iostream>

using namespace std;

long long dp[90] = {0, };
int n;

long long fivo (int n){

    for (int i=2; i<n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n-1];
}
int main(){

    cin >> n;


    dp[0] = 1;
    dp[1] = 1;

    cout << fivo(n);
    return 0;
}