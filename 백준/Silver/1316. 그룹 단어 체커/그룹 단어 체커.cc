#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, result = 0;
    string str;
    bool isGroupWord = true;
    vector<char> v;

    cin >> N;

    for(int i=0; i<N; i++){

        isGroupWord = true;
        cin >> str;

        for(int i=0; i<str.length(); i++){

            auto it = find(v.begin(), v.end(), str[i]);
            if (it != v.end()){ // 이미 있는 단어라면
                if(str[i-1] != str[i]) isGroupWord = false;
            }
            
            v.push_back(str[i]);
        }

        if (isGroupWord) result++;
        v.clear();
    }

    cout << result;
    return 0;
}