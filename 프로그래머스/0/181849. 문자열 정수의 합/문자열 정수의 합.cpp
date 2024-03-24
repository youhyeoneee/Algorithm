#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for(char c : num_str) {
        answer += (int)(c - '0');
    }
    return answer;
}