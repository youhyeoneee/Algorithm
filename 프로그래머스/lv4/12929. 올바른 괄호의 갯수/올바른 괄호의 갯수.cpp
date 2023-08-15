#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<char> charVec;

bool IsRightGwalho()
{
    stack<char> ss;
    
    for(char ch : charVec)
    {
        if (ss.empty()) 
            ss.push(ch);
        else
        {
            if (ss.top() == '(' && ch == ')')   
                ss.pop();
            else
                ss.push(ch);
        }
    }
    
    return ss.empty();
}
int solution(int n) {
    int answer = 0;
    
    // 0. base가 되는 문자열 생성
    
    for(int i=0; i<n; i++)
    {
        charVec.push_back('(');
        charVec.push_back(')');
    }
    
    
    // 정렬
    sort(charVec.begin(), charVec.end());
    
    // 1. 순열 구하기 
    do
    {
        // 2. 올바른 괄호인지 check 
        if (IsRightGwalho())
            answer++;
            
    }while(next_permutation(charVec.begin(), charVec.end()));
    
    
    return answer;
}