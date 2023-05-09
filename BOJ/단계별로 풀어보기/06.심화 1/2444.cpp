#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N; 
stack<pair<int, int>> ss;

void print(int space, int star) {
    for(int i=0; i<space; i++){
        cout << ' ';
    }

    for(int i=0; i<star; i++) {
        cout << '*';
    }

    cout << '\n';
}


int main() {


    cin >> N;

    for(int i=1; i<=N; i++) {        
        ss.push({N-i, (2*i)-1});
        print(N-i, (2*i)-1);
    }

    ss.pop();

    int length = ss.size();


    for(int i=0; i<length; i++) {
        print(ss.top().first, ss.top().second);
        ss.pop();
    }
    // N = 5
    // ' ' : 4 3 2 1 | 0 | 1 2 3 4
    // '*' : 1(2*1-) 3(2*2-1) 5(2*3-1) 7(2*4-1) | 9 | 7 5 3 1

 

    return 0;
}


