#include <iostream>
#include <string>

// 큐
using namespace std;

int N, X, qsize=0;
string cmd;
int arr[10001];

// size: 큐에 들어있는 정수의 개수를 출력한다.
int Size(){
    return qsize;
}

// push X: 정수 X를 큐에 넣는 연산이다.
void Push(int X){
    arr[qsize++] = X;
}

// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int Pop(){
    if (qsize == 0) return -1;
    int result = arr[0];
    for(int i=0; i<qsize-1; i++){
        arr[i] = arr[i+1];
    }
    qsize--;
    return result;
}

// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
bool Empty(){
    if (qsize == 0) return true;
    return false;
}

// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int Front(){
    if (qsize == 0) return -1;
    return arr[0];
}
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int Back(){
    if (qsize == 0) return -1;
    return arr[qsize-1];
}

void print(){
    for(int i=0; i<qsize; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}

int main(){

    cin >> N;

    for (int i=0; i<N; i++){
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
        else if (cmd == "front"){
            cout << Front() << '\n';
        }
        else if (cmd == "back"){
            cout << Back() << '\n';
        }
    }
    return 0;
}