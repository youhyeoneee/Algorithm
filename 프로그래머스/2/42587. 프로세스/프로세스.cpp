#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool isBestPriority(int priority, queue<pair<int, int>> q) {
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (priority < p.first) 
            return true;
    }
    
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;    
    // 위치, 우선순위
    // 처음 위치에 있는 것 까지만 실행 되면 됨
    queue<pair<int, int>> q;

    for(int i=0; i<priorities.size(); i++) {        
        q.push({priorities[i], i});
    }
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        // 큐 안에 자기보다 작은게 있는지 찾기 
        if (isBestPriority(p.first, q)) {
            q.push(p);
        }
        else {
            ++answer;
            
            if (p.second == location) {
                return answer;
            }
        }
    }
    
    return answer;
}