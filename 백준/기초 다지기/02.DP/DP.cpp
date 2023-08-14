#include <bits/stdc++.h>

using namespace std;

// 계산된 결과를 저장하기 위한 DP 테이블 초기화
int d_B[100] = {0, };
int d_T[100] = {0, };

using namespace std;

int fibo_B(int n){
    //첫 번째 피보나치 수와 두 번째 피보나치 수는 1
    d_B[1] = 1;
    d_B[2] = 1;

    //피보나치 함수 반복문으로 구현 (보텀업 DP)
    for (int i=3; i<=n; i++){
        d_B[i] = d_B[i-1] + d_B[i-2];
    }
    return d_B[n];
}


int fibo_T(int n){
    if (n <= 2)
        return 1;
    if (d_T[n] == 0){ // 연산 값이 있는지 없는지 검사 후 없으면 새로 연산
        d_T[n] = fibo_T(n-1) + fibo_T(n-2);
    }
    return d_T[n]; // 있으면 바로 반환
}


int main(void){
    int n = 10; // 10번째 피보나치 수를 계산해보기
    cout << fibo_B(n) << '\n';
    cout << fibo_T(n) << '\n';

    return 0;


}
