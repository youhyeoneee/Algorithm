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
    unordered_map<char, int> strokes;
    strokes.insert({'A', 3});
    strokes.insert({'B', 2});
    strokes.insert({'C', 1});
    strokes.insert({'D', 2});
    strokes.insert({'E', 3});
    strokes.insert({'F', 3});
    strokes.insert({'G', 3});
    strokes.insert({'H', 3});
    strokes.insert({'I', 1});
    strokes.insert({'J', 1});
    strokes.insert({'K', 3});
    strokes.insert({'L', 1});
    strokes.insert({'M', 3});
    strokes.insert({'N', 3});
    strokes.insert({'O', 1});
    strokes.insert({'P', 2});
    strokes.insert({'Q', 2});
    strokes.insert({'R', 2});
    strokes.insert({'S', 1});
    strokes.insert({'T', 2});
    strokes.insert({'U', 1});
    strokes.insert({'V', 1});
    strokes.insert({'W', 2});
    strokes.insert({'X', 2});
    strokes.insert({'Y', 2});
    strokes.insert({'Z', 1});


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