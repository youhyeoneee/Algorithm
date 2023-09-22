#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] > b[0];
    return a[1] > b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    // 끝으로 정렬
    sort(targets.begin(), targets.end(), compare);
    
    // 시작점
    int startX = targets[0][0] + 0.1; 

    for(int i=1; i<targets.size(); i++)
    {

        // 이전 시작점이 다음 끝보다 크거나 같은 경우
        if (startX + 0.1 > targets[i][1])
        {
            // 다른 묶음으로 분류
            startX = targets[i][0];
            answer++;
        }
        else if (startX < targets[i][0])
        {
            startX = targets[i][0];
        }
    }
    
    return answer;
}
