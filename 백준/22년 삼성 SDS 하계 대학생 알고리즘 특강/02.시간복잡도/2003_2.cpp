#include <iostream>

// 수들의 합 2 - 2 포인터
using namespace std;

int A[10001];

int main(){

    int N, M, result = 0;

    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> A[i];
    
    int start = 0, end = 0;
    int sum = A[start];
    for(start; start<N; start++){
        while(sum < M && end < N){
            end++; sum += A[end];
        }
        
        if (sum == M) { result++; } 
        
        sum -= A[start]; 
    }

    cout << result;
    return 0;
}