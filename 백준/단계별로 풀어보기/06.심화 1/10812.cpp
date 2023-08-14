#include <iostream>
#include <queue>

using namespace std;

int N, M, i, j, k;
int arr[101];


void change() {
    
    queue<int> qq;

    for(int a=k; a<=j; a++){
        qq.push(arr[a]);
    }

    for(int a=i; a<k; a++){
        qq.push(arr[a]);
    }

    for(int a=i; a<=j; a++){
        arr[a] = qq.front();
        qq.pop();
    }

}


int main() {


    cin >> N >> M;

    for(int a=1; a<=N; a++) {
        arr[a] = a;
    }

    for(int a=0; a<M; a++){

        cin >> i >> j >> k;

        change();
        
    }

    
    for(int a=1; a<=N; a++) {
        cout << arr[a] << ' ';
    }

    return 0;
}