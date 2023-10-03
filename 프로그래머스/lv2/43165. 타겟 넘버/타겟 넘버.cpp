#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
int answer = 0;

void Dfs(int idx, int num, bool sign, vector<int> &numbers, int &target)
{

    if (idx >= 0 && idx < n) 
    {
        if (sign) num += numbers[idx];
        else num -= numbers[idx];
    }
  
//     cout << "idx : " << idx;
//     if (sign) cout << " +"; else cout << " -"; 
//     cout << num << "\n";

    
    if (idx == n-1)
    {
        if (num == target) answer++;        
        return;
    }
           
    Dfs(idx+1, num, true, numbers, target);
        
    Dfs(idx+1, num, false, numbers, target);

}

int solution(vector<int> numbers, int target) 
{
    
    n = numbers.size();
    
    Dfs(-1, 0, true, numbers, target);
    
    return answer;
}