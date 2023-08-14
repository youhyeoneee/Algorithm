#include <iostream>
#include <string>

using namespace std;

bool isHANSU(int n){
    if (n>=100){
        string str = to_string(n);
        int a = (str[0]-'0') - (str[1]-'0'); // 연속된 두 개의 수의 차이
        for (int i=1; i<str.length()-1; i++)
            if (a != (str[i]-'0') - (str[i+1]-'0')) return false;         
    }

    return true;
}

int main(){

    int N, result = 0;

    cin >> N;


    for (int i=1; i<=N; i++)
        if (isHANSU(i)) result++;
    
    cout << result << '\n';

    return 0;
}