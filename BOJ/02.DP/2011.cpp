#include <iostream>
#include <string>
#include <cmath>
#include <string.h>

#define MOD 1000000

using namespace std;
 
bool is_alpha(string code, int n){ // n번째 자리+ n-1번째자리가 0~26인가 ex. 25114, 3 -> true(11)
    int idx = code.length() - n; // 암호 끊을 길이
    string a = code.substr(idx, 2);
    // cout << ">>>>>" << idx <<  "; " << a << endl;
    if (stoi(a) > 26)
        return false;
    else if (a[0] == '0')
        return false;
    else
        return true;
    
   
    
}

int main(){

    string code;

    cin >> code;

    int length = code.length(); // 암호 길이

    long long dp[length+1] = {0, }; // 길이로 자른 나올 수 있는 암호!
    memset(dp, 0, sizeof(dp));


    int n = stoi(code); // 암호 string -> int 로 변환
   
    dp[1] = (n!=0)? 1 : 0; // N번째 글자로 나오는 건 하나뿐

    if (length > 1){
        dp[2] = (is_alpha(code, 2))? 2 : 1;

        for (int i=3; i<=length; i++){
            dp[i] = dp[i-1];
            if (is_alpha(code, i)){
                dp[i] += dp[i-2];
                // cout << dp[i-11] << "+ " << dp[i-2] << endl;
            }
            dp[i] %=MOD;
        }

    }
   
    cout << dp[length] << endl;

    return 0;
}