#include <iostream>

// 수들의 합 2
using namespace std;

int A[10001];

int main(){

    int N, M, result = 0;

    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> A[i];

    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += A[j];
            if (sum == M){
                result++;
                break;
            }
        }
    }

    cout << result;

    return 0;
}