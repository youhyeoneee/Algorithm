#include <iostream>
#include <string>

// 사전

using namespace std;

long long dp[2501][2501]; // nCk 저장 dp[n][k] = dp[n-1][k-1] + dp[n-1][k]

long long factorial(long long n){
    if (n <= 1) return 1;
    return n*factorial(n-1);
}


long long combination(int n, int k){
    return dp[n][k];
}


long long N, M, K;
string result = "";

int main(){

    cin >> N >> M >> K;

     for(long long n=0; n<=N+M-1; n++){
        for(long long k=0; k<=n; k++){
            if (k==0) dp[n][k] = 1;
            else if (k==n) dp[n][k] = 1;
            else dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
        }
        
    }

    long long str_size = N+M;
    long long num = combination(str_size-1, M)+combination(str_size-1, M-1);
    if (K > num) cout << -1 <<'\n';
    else{
        while(K>0 && result.size() < str_size){
            long long a_or_b = combination(N+M-1, M);
            if(K<=a_or_b) {
                result += 'a'; 
                N--; 
            }
            else { 
                result += 'z'; 
                M--;
                K-=a_or_b;
            }
        }

        cout << result << '\n';
    }

    return 0;
}