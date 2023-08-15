#include <iostream>
#include <string>
#include <vector>

#define INF 987654321
#define MAX 20004

using namespace std;

int dp[MAX]; 

void Init()
{
    for(int i=1; i<MAX; i++)
    {
        dp[i] = INF;
    }
}

int solution(vector<string> strs, string t)
{
    
    // 배열 초기화 
    Init();
    
    int answer = -1;
    
    // 1부터 t의 길이까지 부분 문자열을 뽑는다.
    for(int len=1; len<=t.length(); len++)
    {
        
        string subStr = t.substr(0, len);
        
        // 단어 조각
        for(string word : strs)
        {
            // 시작 인덱스 (ex. bana(4) - na(2) - 2 > 0)
            int startIdx = len - word.length(); 
            
            // 길이가 크면 패스
            if (startIdx < 0)
                continue;
            
            // 길이가 작거나 같으면 완전히 같은 지 검사
            // ba"na" == "na" ? 
            bool isSame = true;
            
            for(int i=0; i<word.length(); i++)
            {
                if (subStr[startIdx + i] != word[i])
                {
                    isSame = false;
                    break;
                }
            }
            
            // 같지 않으면 패스
            if (!isSame)
                continue;
                        
            dp[len] = min(dp[len], dp[startIdx] + 1);
        }
    }
 
	
    
    // 갱신이 되었다면 리턴 
    if (dp[t.length()] != INF)
        answer = dp[t.length()];
    
    return answer;
}