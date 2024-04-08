#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    for(string name : participant) {
        m[name] += 1;
    }
        
    for(string name : completion) {
        m[name] -= 1;
    }
    
    
    for(auto i : m) {
        if (i.second) {
            answer = i.first;
            break;
        } 
    }

    
    return answer;
}