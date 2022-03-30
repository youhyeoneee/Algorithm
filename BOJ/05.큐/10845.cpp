#include <iostream>
#include <string>

using namespace std;


int queue[100001];
int q_size = 0;

// push X: 정수 X를 큐에 넣는 연산이다.
void push(int X){
    queue[q_size++] = X;
}

// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(){
    if (q_size == 0)
        return -1;
    int result = queue[0];

    for (int i=1; i<q_size; i++)
        queue[i-1] = queue[i];

    q_size--;
    return result;
}

// size: 큐에 들어있는 정수의 개수를 출력한다.
int size(){
    return q_size;
}

// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
bool empty(){
    if (q_size == 0)
        return true;
    else
        return false;
}

// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(){
    if (q_size == 0)
        return -1;
    else   
        return queue[0];    
}
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(){
    if (q_size == 0)
        return -1;
    else 
        return queue[q_size-1];
}

int main(){
    int N, X;

    cin >> N;

    string cmd;
    for (int i=0; i<N; i++){
        cin >> cmd;

        if (cmd.find("push") == 0){
            cin >> X;
            push(X);
        }
        else if (cmd.find("pop") == 0){
            cout << pop() << '\n';
        }
        else if (cmd.find("size") == 0){
            cout << size() << '\n';
        }
        else if (cmd.find("empty") == 0){
            cout << empty() << '\n';
        }
        else if (cmd.find("front") == 0){
            cout << front() << '\n';
        }
        else if (cmd.find("back") == 0){
            cout << back() << '\n';
        }     
    }
    
   return 0; 
}