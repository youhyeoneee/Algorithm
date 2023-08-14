#include <iostream>

using namespace std;

int main(){

    int A;

    cin >> A;

    int Ai[A+1] = {0,};

    for(int i=1; i<=A; i++)
        cin >> Ai[i];

    int a[A+1] = {1, };
    int b[A+1] = {1, };

    // dp[N] = 가장 긴 바이토닉 수열 
    // = [1~N-1] 까지 가장 긴 증가 부분 수열 + 1(N) + [N+1 ~ A] 까지 가장 긴 감소 부분 수열
    
    for(int i=1; i<=A; i++){
        a[i] = 1;
        for(int j=1; j<i; j++){
            if(Ai[j] < Ai[i]){
                a[i] = max(a[j]+1, a[i]);
            }
        }

    }

    for (int i=A; i>=1; i--){
        b[i] = 1;
        for (int j=A; j>i; j--){
            if(Ai[j] < Ai[i]){
                b[i] = max(b[j]+1, b[i]);
            }
        }
    }

    int result = 0;
   for (int i=1; i<=A; i++){
       int sum = a[i] + b[i] - 1;
       if (result < sum)
            result = sum;
    }

    cout << result << endl;

    return 0;
}