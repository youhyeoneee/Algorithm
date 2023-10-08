#include <string>
#include <vector>

using namespace std;

int dp[101][101]; 

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    for(vector<int> puddle : puddles)
    {
        dp[puddle[1]][puddle[0]] = -1;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            // 물웅덩이는 패스
            if (dp[i][j] == -1)
                continue;
            
            int a = 0;
            int b = 0;
            if (dp[i-1][j] != -1) // 위쪽이 물웅덩이가 아닐 경우
                a = dp[i-1][j];
            if (dp[i][j-1] != -1) // 왼쪽이 물웅덩이가 아닐 경우
                b = dp[i][j-1];
            dp[i][j] += (a+b) % 1000000007;
        }
    }
    return dp[n][m];
}