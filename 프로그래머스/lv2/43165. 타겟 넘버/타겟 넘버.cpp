#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
int answer = 0;

void Dfs(int idx, int num, bool sign, vector<int> &numbers, int &target)
{

    // 부호에 따라 숫자 더하기, 빼기
    if (idx >= 0 && idx < n) 
    {
        if (sign) num += numbers[idx];
        else num -= numbers[idx];
    }
    
    // 기저 사례 : 마지막 숫자까지 처리
    if (idx == n-1)
    {
        if (num == target) answer++;        
        return;
    }
           
    // 더하기
    Dfs(idx+1, num, true, numbers, target);
    // 빼기 
    Dfs(idx+1, num, false, numbers, target);

}

int solution(vector<int> numbers, int target) 
{
    
    n = numbers.size();
    
    Dfs(-1, 0, true, numbers, target);
    
    return answer;
}