#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int>> dp[20004]; 


int solution(vector<string> strs, string t)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    // 문자열 길이대로 넣기 
    for(string str : strs)
    {
        dp[str.length()].push_back({str, 1});
    }

    // dp 실행
    // 0부터 문자열 길이까지
    for(int i=1; i<t.length(); i++)
    {
        // i = 2면
        
            
        for(int j=0; j<i; j++)
        {
                    for(auto : dp[n-i])
            // 2 = {2} + 0
            // 1 = {1} + {1}
            dp[i] = dp[i-j] + dp[j];
            
            
        }
        
        
    }
 
    

    return answer;
}

// strs 1~100개 
// banana 
// ba + na + na = 3개
// ba + na + n + a = 4개
// ba + n + a + n + a = 5개

// app, ple, ap, pp, p, l, e
// apple
// app + l + e 
// ple + ap 
// ap + p + l + e
// p + l + e + ap
// l + app + e
// l + ap + p + e
//



// dp 인 것 같다 ..


// 5 = 4+1 = 3+2 = 2+3 = 1+4

// 4 = 3+1 = 2+2 = 1+3
// 4+0 : X
// 3+1 : ba + n + a (3), na + n + a (3), n + a + n + a (4), a + n + a + n (4), a + na + n (3)
// 2+2 : ba + na (2), ba + n + a (3), na + n + a (3), n + a + na (3), ...
// 1+3 : n + a + n + a (4) 

// 3 = 2+1 = 1+2 (string 내에 없거나, 이미 있으면 없애기)
// 3+0 : X
// 2+1 : ba + n (2) , na + n (2) , n + a + n (3), a + n + a (3)
// 1+2 : a + na (2)

// 2 = 2+0 = 1+1
// 2+0 : ba (1), na (1)
// 1+1 = n + a (2), a + n (2)

// 1 = 1+0
// 1개짜리 : n (1) , a (1)

// a + p + p + l + e
// ap + p + l + e
// ap + pl + e
// ap + p + le
