#include <iostream>
#include <string>

// 스택

using namespace std;

int N, X, top=0;
string cmd;

int arr[10001];

// push X: 정수 X를 스택에 넣는 연산이다.
void Push(int X){
    arr[top++] = X;
}
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int Pop(){
    if(top==0) return -1;
    return arr[--top];
}
// size: 스택에 들어있는 정수의 개수를 출력한다.
int Size(){
    return top;
}
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
bool Empty(){
    if (top==0)
        return true;
    return false;
}
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int Top(){
    if(top==0) return -1;
    return arr[top-1];
}


void print(){
    for(int i=0; i<top; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}

int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cmd;

        if (cmd == "push") {
            cin >> X;
            Push(X);
        }
        else if (cmd == "pop"){
            cout << Pop() << '\n';
        }
        else if (cmd == "size"){
            cout << Size() << '\n';
        }
        else if (cmd == "empty"){
            cout << Empty() << '\n';
        }
        else if (cmd == "top"){
            cout << Top() << '\n';
        }
    }
    return 0;
}