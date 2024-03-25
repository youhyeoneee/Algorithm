#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int size = 3;
    vector<int> scores(size);
    
    // 10,000
    for(int i=0; i<answers.size(); i++) {
        if (answers[i] == one[i % one.size()]) scores[0]++;
        if (answers[i] == two[i % two.size()]) scores[1]++;
        if (answers[i] == three[i % three.size()]) scores[2]++;
    }
    
    int maxAnswer = *max_element(scores.begin(), scores.end());
    
    vector<int> answer;       
    for(int i=0; i<scores.size(); i++) {
        if (scores[i] == maxAnswer) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}