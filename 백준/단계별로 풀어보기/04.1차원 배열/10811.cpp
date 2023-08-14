#include <iostream>
#include <stack>

using namespace std;

int main() {

    int basket[101];
    int N, M, i, j;

    cin >> N >> M;

    for(int a=1; a<=N; a++) {
        basket[a] = a;     
    }



    for(int a=0; a<M; a++) {

        cin >> i >> j;

        stack<int> s;

        for (int b=i; b<=j; b++) {
            s.push(basket[b]); 
        }

        for (int b=i; b<=j; b++) {
            basket[b] = s.top();
            s.pop(); 
        }
    }

    for(int a=1; a<=N; a++) {
        cout << basket[a] << " ";     
    }


    return 0;
}