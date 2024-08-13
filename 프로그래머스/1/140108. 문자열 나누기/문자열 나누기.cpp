#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    while(s.length()) {  
        answer++;
        char x = s[0];
        int x_cnt = 0, not_x_cnt = 0;
        int idx = 0;
        
        for(idx; idx<s.length(); idx++) {
            if (s[idx] == x) {
                x_cnt++;
            } else {
                not_x_cnt++;
            }
            if (x_cnt == not_x_cnt) {
                break;
            } 
        }
        
        if (idx+1 <s.length())
            s = s.substr(idx+1);
        else
            break;
    }
    
    return answer;
}