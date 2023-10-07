#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    // 같은 숫자인 경우
    if (N == number)    
        return 1;
    
    set<int> dp[8];
    int num = 0;

    // 초기화 
    for(int i=0; i<8; i++)
    {
        num = num * 10 + N;
        dp[i].insert(num);
    }
    
    // dp[i] = dp[j] + dp[i-j-1]
    // ex. dp[3] = dp[0] + dp[3-0-1] = dp[0] + dp[2]
    //          = dp[1] + dp[3-1-1] = dp[1] + dp[1]
    for(int i=1; i<8; i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int a : dp[j])
            {
                for(int b : dp[i-j-1])
                {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if (b != 0) dp[i].insert(a/b);
            
                }
            }
        }
        
    }
    
    for(int i=0; i<8; i++)
    {
        if (dp[i].find(number) != dp[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}