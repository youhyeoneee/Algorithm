#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void Dfs(int idx, int sum, vector<int> &numbers, int &target)
{    
    // 기저 사례 : 마지막 숫자까지 처리
    if (idx == numbers.size())
    {
        if (sum == target) answer++;        
        return;
    }
           
    Dfs(idx+1, sum + numbers[idx], numbers, target);  // 더하기
    Dfs(idx+1, sum - numbers[idx], numbers, target);  // 빼기 

}

int solution(vector<int> numbers, int target) 
{
        
    Dfs(0, 0, numbers, target);
    
    return answer;
}