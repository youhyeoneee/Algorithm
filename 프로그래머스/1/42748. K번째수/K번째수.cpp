#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> cmd : commands) { // 50 
        int i = cmd[0];
        int j = cmd[1];
        int k = cmd[2];
        
        vector<int> v;
        // vector i ~ j 
        for(int idx=i-1; idx<j; idx++) {
            v.push_back(array[idx]);
        }
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[k-1]);
    }
    return answer;
}