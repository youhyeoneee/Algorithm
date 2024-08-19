#include <iostream>
#include <stack>

using namespace std;


// 10:54~

int K;

int main(){

    cin >> K;

    int num;
    stack<int> s;

    for(int i=0; i<K; i++) {
        cin >> num;

        if (num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
    }

    int answer = 0;
    while(!s.empty()) {
        answer += s.top();
        s.pop(); 
    }

    cout << answer;

    return 0;
}
