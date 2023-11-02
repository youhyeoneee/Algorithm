#include <string>
#include <vector>
#include <queue>

using namespace std;


queue<string> vecToQueue(vector<string> cards)
{
    queue<string> q;
    
    for(string str : cards)
    {
        q.push(str);
    }
    
    return q;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    
    queue<string> cq1 = vecToQueue(cards1);
    queue<string> cq2 = vecToQueue(cards2);

    int idx = 0;
    bool result = true;
    
    while(idx < goal.size() && result)
    {
        string goal_str = goal[idx];
        
        if (cq1.front() == goal_str)
        {
            cq1.pop();
            idx++;
            continue;
        } 
        else if (cq2.front() == goal_str)
        {
            cq2.pop();
            idx++;
            continue;
        }
        else 
        {
            result = false;
            break;
        }  
        
    }
    

    return (result == true)? "Yes" : "No";
}