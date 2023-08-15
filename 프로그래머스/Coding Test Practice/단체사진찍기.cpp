
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

bool checkCondition(char opr, int num, int diff) {
        if(opr == '=') 
            return num == diff;
        else if(opr == '>') return diff > num;
        else return diff < num;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    vector<vector<char>> s;
    sort(friends.begin(), friends.end());
    
    do{
        bool check = true;
        
        for(string text: data){
            int firstIdx = friends.find(text[0]); // N의 위치
            int secondIdx = friends.find(text[2]); // F의 위치
            int diff = abs(firstIdx - secondIdx)-1; // N과 F의 차이 
            cout << diff << endl;
            int num = text[4] - '0'; // 
            if(checkCondition(text[3], num, diff)) continue;
            check = false;
            break;
        }
        if(check) answer++;
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}

int main() {
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};
    // vector<string> data = {"M~C<2", "C~M>1"};
	solution(n, data);
	return 0;
}