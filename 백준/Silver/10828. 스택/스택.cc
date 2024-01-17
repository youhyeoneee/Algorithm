#include <iostream>
#include <string>

using namespace std;

int arr[100001]; //명령의 수 N (1 ≤ N ≤ 10,000)
int idx = 0;

// push X: 정수 X를 스택에 넣는 연산이다.
void push(int X){
    arr[idx++] = X;
}
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop(){
    if (idx-1 != -1){
        cout << arr[--idx] << '\n';
    }
    else
        cout << -1 << '\n';

}
// size: 스택에 들어있는 정수의 개수를 출력한다.
void size(){
    cout << idx << '\n';
}
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
void empty(){
    if (idx == 0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void top(){
    if (idx-1 != -1){
        cout << arr[idx-1] << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main(){
    int N;
    string cmd; 
    int X;

    cin >> N;

    for (int i=0; i<N; i++){
        //명령
        cin >> cmd;
        if (cmd.find("push") == 0){
            cin >> X;
            push(X);
        }
        else if (cmd.find("pop") == 0)
            pop();
        else if (cmd.find("size") == 0)
            size();
        else if (cmd.find("empty") == 0)
            empty();
        else if (cmd.find("top") == 0)
            top();
    }

    return 0;
}