#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

stack<char> ss;
queue<char> qq;

bool isSame(char a, char b) {
    return a == b;
}

bool isPall = false;

int main() {

    string str;

    cin >> str;

    for(int i=0; i<str.length(); i++) {
        ss.push(str[i]);
        qq.push(str[i]);
    }

    for(int i=0; i<str.length(); i++) {
        
        isPall = isSame(ss.top(), qq.front());
        if (!isPall) break;
        ss.pop();
        qq.pop();
    }

    cout << (int)isPall << '\n';


    return 0;
}