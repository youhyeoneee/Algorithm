#include <iostream>
#include <string>

using namespace std;


int deque[10001];
int d_size = 0;

// push_front X: 정수 X를 덱의 앞에 넣는다.
void push_front(int X){
    for (int i=d_size; i>0; i--){ // 오른쪽으로 한 칸씩 밀기 
        deque[i] = deque[i-1];
    }
    deque[0] = X;
    d_size++;
}
// push_back X: 정수 X를 덱의 뒤에 넣는다.
void push_back(int X){
    deque[d_size++] = X;
}
// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop_front(){
    if (d_size == 0)
        cout << -1 << '\n';
    else{
        cout << deque[0] << '\n';
        for (int i=0; i<d_size-1; i++){ // 왼쪽으로 한 칸씩 밀기 
            deque[i] = deque[i+1];
        }
        d_size--;
    }
}
// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop_back(){
    if (d_size == 0)
        cout << -1 << '\n';
    else{
        cout << deque[d_size-1] << '\n';
        d_size--;
    }
}
// size: 덱에 들어있는 정수의 개수를 출력한다.
void size(){
    cout << d_size << '\n';    
}
// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
void empty(){
    if (d_size == 0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
// front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void front(){
    if (d_size == 0)
        cout << -1 << '\n';
    else
        cout << deque[0] << '\n';
}
// back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void back(){
    if (d_size == 0)
        cout << -1 << '\n';
    else
        cout << deque[d_size-1] << '\n';
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, X;
    string cmd;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cmd;

        if (cmd.find("push_front") == 0){
            cin >> X;
            push_front(X);
        }
        else if (cmd.find("push_back") == 0){
            cin >> X;
            push_back(X);  
        }
        else if (cmd.find("pop_front") == 0){
            pop_front();  
        }
        else if (cmd.find("pop_back") == 0){
            pop_back();  
        }
        else if (cmd.find("size") == 0){
            size();  
        }
        else if (cmd.find("empty") == 0){
            empty();  
        }
        else if (cmd.find("front") == 0){
            front();  
        }
        else if (cmd.find("back") == 0){
            back();  
        }
    }

    return 0;
}