#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> v(n, 1);
    
    for(int i : reserve) {
        v[i-1] = 2;
    }
    
    for(int i : lost) {
        v[i-1]--;
    }
    
        
    for(int i=0; i<v.size(); i++) {
       if (v[i] == 0) {
           // 앞 
           if (v[i-1] == 2) {
               v[i-1]--;
               v[i]++;
           }
           // 뒤
           else if (v[i+1] == 2) {
               v[i+1]--;
               v[i]++;
           }
       }
    }
    
    for(int i : v) {
        if (i > 0) answer++;
    }
    return answer;
}