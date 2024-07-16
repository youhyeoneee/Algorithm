#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> calculate(vector<int> v) {
    vector<int> temp;

    for(int i=0; i<v.size(); i+=2) {            
        if (i+1 != v.size()) {
            int sum = (v[i] + v[i+1]) % 10;
            temp.push_back(sum);
        } else {
            temp.push_back(v[i]);
        }
    }

    return temp;
}


int main() {

    // input
    string S;
    cin >> S; 


    // solve
    unordered_map<char, int> strokes = {
        {'A', 3}, {'B', 2}, {'C', 1}, {'D', 2}, {'E', 3}, {'F', 3},
        {'G', 3}, {'H', 3}, {'I', 1}, {'J', 1}, {'K', 3}, {'L', 1},
        {'M', 3}, {'N', 3}, {'O', 1}, {'P', 2}, {'Q', 2}, {'R', 2},
        {'S', 1}, {'T', 2}, {'U', 1}, {'V', 1}, {'W', 2}, {'X', 2},
        {'Y', 2}, {'Z', 1}
    };

    // 문자열 -> 숫자로 변환
    vector<int> v;
    for(char ch : S) {
        auto iter = strokes.find(ch);
        if (iter != strokes.end())
            v.push_back(iter->second);
    }

    // 더하기
    while(true) {
        if(v.size() == 1) {
            if (v[0] % 2 == 0) 
                cout << "You're the winner?\n";
            else 
                cout << "I'm a winner!\n";
        
            return 0;
        } else {
            v = calculate(v);
        }
    }
    return 0;

}