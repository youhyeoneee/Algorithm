#include <iostream>
#include <vector>

using namespace std;

int main() {

    int arr[101] = {0, };
    int N, M;
    int i, j, k;

    cin >> N >> M;

    for(int a=0; a<M; a++) {
        cin >> i >> j >> k;

        for(int b=i; b<=j; b++){
            arr[b] = k;
        }
    }

    for(int a=1; a<=N; a++) {
        
        cout << arr[a] << " ";        
    }

    return 0;
}