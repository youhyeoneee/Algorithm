#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// hhmm -> m
int timeToInt(string hhmm)
{
    return (60 * stoi(hhmm.substr(0, 2))) + stoi(hhmm.substr(3));
}

bool compare(vector<string> a, vector<string> b)
{
    return timeToInt(a[1]) < timeToInt(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> pauseSubjects;
    
    // 1. 과제 시작 시간 순대로 정렬 
    sort(plans.begin(), plans.end(), compare);
    
    int currTime = timeToInt(plans[0][1]);
    int nextTime = timeToInt(plans[1][1]);
    int idx = 0;

    while(idx < plans.size() || !pauseSubjects.empty())
    {
        // 멈춰놨던 과제 처리
        if (!pauseSubjects.empty())
        {
            // 마지막 순서 과제 처리가 끝났다면
            if (idx == plans.size())
            {
                answer.push_back(pauseSubjects.top().first);
                pauseSubjects.pop();
                continue; 
            }
            
            // 현재 시간이 다음 과제 실행 시간보다 작다면 
            if (currTime < nextTime)
            {
                // 남은 시간 동안 멈춰 놨던 과제 하기 

                int remainTime = pauseSubjects.top().second;
                int availableTime = nextTime - currTime;
                
                
                if (remainTime <= availableTime) // 과제 완료 
                {
                    answer.push_back(pauseSubjects.top().first);    
                    pauseSubjects.pop();
                    currTime += remainTime;
                }
                
                else // 과제 미완료
                {
                    pauseSubjects.top().second = remainTime - availableTime;
                    currTime = nextTime;
                }
                
                continue;
            }
        }
       
        // 다음 과제 처리 
        currTime = timeToInt(plans[idx][1]) + stoi(plans[idx][2]);
        nextTime = idx+1 >= plans.size()? 1440 : timeToInt(plans[idx+1][1]);

    
        if (currTime > nextTime) 
        {
            // 과제 중지 
            pauseSubjects.push({plans[idx][0], currTime - nextTime});
            currTime = nextTime;
        }
        else 
        { 
            // 과제 완료 
            answer.push_back(plans[idx][0]);    
        }
        
        ++idx; 
    }
    
       
    return answer;
}

