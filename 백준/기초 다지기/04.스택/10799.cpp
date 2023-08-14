#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> a;

int main(){

    string text;
    cin >> text;

    int cnt = 0;

    for (int i=0; i<text.length(); i++){
        if(text[i] == '('){ 
            a.push(text[i]);
        }
        else if (text[i-1] == '(' && text[i] == ')'){ // 레이져
            a.pop();
            cnt += a.size();
        }
        else if (text[i-1] == ')' && text[i] == ')'){ // 쇠막대 끝
            a.pop();
            cnt ++;
        }

    }

    cout << cnt << '\n';
    
    return 0;
}