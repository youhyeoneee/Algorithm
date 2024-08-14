#include <string>
#include <vector>

using namespace std;

bool skipAlphabets[26];

int changeIdx(int currIdx, int idx) {
    int cnt = 0;
    
    while(cnt < idx) {
        currIdx = (currIdx + 1) % 26;
        if (skipAlphabets[currIdx]) {
            continue;
        }
        
        cnt++;
    }
    
    return currIdx;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char ch : skip) {
        skipAlphabets[ch - 'a'] = true;
    }
        
    for(char ch : s) {
        int idx = changeIdx(ch - 'a', index);
        answer += (char)(idx + 'a');
    }
    
    return answer;
}