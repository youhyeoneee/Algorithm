#include <iostream>

using namespace std;

int arr[51];

long long dp[2501][2501]; // nCk 저장 dp[n][k] = dp[n-1][k-1] + dp[n-1][k]

int factorial(int n){
    if (n <= 1) return 1;
    return n*factorial(n-1);
}


long long combination(int n, int k){
    return dp[n][k];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, K, N = 0;

    cin >> M; // 조약돌의 색상은 1부터 M까지 중의 하나

    for (int i=1; i<=M; i++) {
        cin >> arr[i]; 
        N += arr[i];
    } 

    cin >> K;

    for(int n=0; n<=N; n++){
        for(int k=0; k<=n; k++){
            if (k==0) dp[n][k] = 1;
            else if (k==n) dp[n][k] = 1;
            else dp[n][k] = dp[n-1][k-1] + dp[n-1][k];

            // cout << "dp[" << n << "][" << k << "] = " << dp[n][k] << '\n'; 

        }
        
    }
    
    long long a = 0, b; // 분자 / 분모 

    for(int i=1; i<=M; i++){
        a+= combination(arr[i], K); // 같은 색상으로 K개 뽑는 조합
    }

    b = combination(N, K); // N개에서 K개 뽑는 조합
    double result = (double)a/(double)(b);
    cout << fixed;
    cout.precision(20);
    if (result == 1.0) cout << "1.0\n";
    else cout << result << '\n';

    return 0;
}