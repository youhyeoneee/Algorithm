#include <string>
#include <vector>

using namespace std;

bool skipAlphabets[26];

char changeAlphabet(char a, int idx) {
    
    int cnt = 0;
    int aIdx = a - 'a';
    
    while(cnt < idx) {
        aIdx = (aIdx + 1) % 26;
        if (skipAlphabets[aIdx]) {
            continue;
        }
        
        cnt++;
    }
    
    return (char)(aIdx + 'a');
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char ch : skip) {
        skipAlphabets[ch - 'a'] = true;
    }
    
    int mod = 26;
    
    for(char ch : s) {
        answer += changeAlphabet(ch, index);
    }
    
    return answer;
}