#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 09:30 ~ 

vector<int> solve(vector<int> commands) 
{

    vector<int> results;
    priority_queue<int> pq;

    for(int c : commands) 
    {
        if (c == 0) 
        { // 큰 값 출력 후 제거 
            if (pq.empty())
            {
                results.push_back(0);
            } 
            else 
            { 
                results.push_back(pq.top());
                pq.pop();
            } 
        } 
        else {
            pq.push(c);
        }
    }

    return results;
}

void output(vector<int> results) 
{
    for(int i : results) 
    {
        cout << i << '\n';
    }
}

void input() 
{
    int cmd;
    int n;
    vector<int> commands;

    cin >> n;
    for(int i=0; i<n; i++) 
    {
        cin >> cmd;
        commands.push_back(cmd);
    }

    output(solve(commands));
}


int main() 
{
    input();

    return 0;
}