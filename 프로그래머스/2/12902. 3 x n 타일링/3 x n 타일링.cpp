#include <string>
#include <vector>

#define MOD 1000000007
using namespace std;

long long dp[5004];

int solution(int n) {    
    if (n%2) {
      return 0;  
    } 
    
    dp[0] = 1;
    dp[2] = 3; 
    
    for(int i=4; i<=n; i+=2) {
        dp[i] = dp[i-2] * 3;
        for(int j=4; j<=i; j+=2) {
            dp[i] += dp[i-j] * 2;
        }
        
        dp[i] %= MOD;
    }
    
    return dp[n] % MOD; 
}