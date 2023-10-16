#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;



int solution(vector<int> scoville, int K) {
    int answer = 0;
        
    // 오름차순 priority_queue
    priority_queue<int, deque<int>, greater<int>> pq;
    
    for(int s : scoville)
    {
        pq.push(s);    
    }
        
    while(pq.size() > 1)
    {
        // 가장 안매운 음식의 스코빌 지수가 K 이상인지 
        if (pq.top() >= K)
            break;
        
        // 가장 안매운 음식
        int a = pq.top();
        pq.pop();
        
        // 2번째로 안매운 음식 
        int b = pq.top();
        pq.pop();
        
        // 섞기
        pq.push(a + (b * 2));
        
        // 섞은 횟수 증가
        answer++;
    }
    
    // 가장 안매운 음식의 스코빌 지수가 K 이상이 안된다면 
    if (pq.top() < K) answer = -1;
    
    return answer;
}