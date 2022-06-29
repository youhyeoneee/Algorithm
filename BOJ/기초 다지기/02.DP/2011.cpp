#include <iostream>
#include <string>
#include <string.h>

#define MOD 1000000

using namespace std;


int main(){

    string code;
    cin >> code;

    int length = code.length(); // 암호 길이 1~5000

    long long dp[length+1] = {0, }; //나올 수 있는 해석의 가짓수를 1000000으로 나눈 나머지
    memset(dp, 0, sizeof(dp)); // 0으로 초기화

    int num[length+1]; // 문자열 -> int 
    for (int i=0; i<length; i++)
        num[i+1] = code[i] - '0'; // 문자열 -> int 
    
    if (num[1] == 0)  // 1. 맨 앞자리가 0일 경우 -> 0
        dp[length] = 0;

    else{
        dp[0] = 1;
            // 1자리 암호일 경우
        dp[1] = 1; // 1~9 = 1
        for (int i=2; i<=length; i++){
            if (num[i] == 0){  // 2. 현재 숫자가 0일 경우 : 앞에 숫자가 1이나 2면 OK 아니면 0 
                if (num[i-1] == 1 || num[i-1] == 2) // 10, 20
                    dp[i] = dp[i-2];
                else // 30, 40, ...
                    dp[i] = 0;
            }
            else{ // 2. 현재 숫자가 0이 아닐 경우
                int a = num[i-1] * 10 + num[i] ;
                if (a<= 26 && num[i-1] != 0){  // 11~19, 21~26 
                    dp[i] = dp[i-1] + dp[i-2]; 
                }

                else{ // 27 이상이거나 01~09
                    dp[i] = dp[i-1]; 
                }
            }
            
            dp[i] %= MOD;
        }
    }
    cout << dp[length] << endl;
    

    return 0;
}