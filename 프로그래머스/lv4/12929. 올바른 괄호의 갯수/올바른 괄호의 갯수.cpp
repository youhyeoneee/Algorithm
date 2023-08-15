#include <string>
#include <vector>

using namespace std;

int dp[15];


int solution(int n) {
    
    int answer = 0;
   
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++)
    {        
        int mmax = i-1;
        
        for(int j=0; j<=mmax; j++)
        {
             dp[i] += dp[mmax-j] * dp[j];
        }
    }
    return dp[n];
}