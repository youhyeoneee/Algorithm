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
    
    // 1. 점화식을 cache[t의 인덱스] = min(cache[t의 인덱스], cache[t의 인덱스 - 원소 길이] + 1)로 설정해줍니다.
    
    // 1.1 여기서 cache[t의 인덱스]란 t의 인덱스까지의 부분 문자열을 뽑았을 때 단어 조각들의 최소 숫자입니다.

    // 2. 이중 반복문을 통해 위 점화식을 구해줍니다.
    
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
 
    // 3. cache[t의 길이]가 INF라면 문자열을 단어 조각들로 형성 못하므로 -1을 반환해주고, 그 외 케이스는 cache[t의 길이]를 반환해줍니다.
    // 3.1 cache[t의 길이] = t의 길이까지의 부분 문자열을 이루는 단어 조각들의 최소 숫자 = t를 이루는 단어 조각들의 최소 숫자
    
    if (dp[t.length()] != INF)
        answer = dp[t.length()];
    
    return answer;
}
