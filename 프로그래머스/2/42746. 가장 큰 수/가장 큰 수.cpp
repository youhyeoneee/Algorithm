#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // string 으로 변환
    vector<string> stringNumbers;
    
    for(int num : numbers) {
        string stringNum = to_string(num);
        stringNumbers.push_back(stringNum);
    }
        
    sort(stringNumbers.begin(), stringNumbers.end(), compare);
    
    for(string strNum : stringNumbers) {
        answer += strNum;
    }
    

    // 모두 0인 경우 : 맨 앞자리 0일 것
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}