#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool isDiff(char a, char b){
    if (a == '(' && b == ')')
        return true;
    else 
        return false;
}

void isVPS(stack<char> a){ 

    // a-> b스택으로 옮기면서
    // top을 비교해 () 이면 각각 pop
    // 둘 다 비었으면 VPS!
    stack<char> b;

    int length = a.size();
    for (int i=0; i<length; i++){
        if (!b.empty()){
            if (isDiff(a.top(), b.top())){
                a.pop();
                b.pop();
            }

            else{
                b.push(a.top()); 
                a.pop();
            }
        }
        else{ // 비었을 때는 걍 넣는다. 
            b.push(a.top()); 
            a.pop();
        }
    }

    if (b.empty())
        cout << "YES" << '\n';
    else   
        cout << "NO" << '\n';
}
int main(){

    int T; // 테스트 데이터
    string data; // 입력 문자열
    cin >> T;

    for (int i=0; i<T; i++){
        cin >> data;
        stack<char> a; // 스택
        for (int j=0; j<data.length(); j++){
            a.push(data[j]); // 한 글자씩 스택에 넣기
        }
        isVPS(a);
        
    }

    return 0;
}