#include <iostream>
#include <string>
#include <algorithm>
// 실버 5

using namespace std;

int main(){

    string S;

    cin >> S;



    char now = S[0]; // 현재 0인지 1인지
    int num0 = 0, num1 = 0; // 0묶음, 1묶음 숫자

    for(int i=1; i<S.size(); i++){
        if (now != S[i]){
            if (now == '0')
                num0++;
            else
                num1++;
            now = S[i];
        }

        if(i == S.size()-1){ // 마지막 숫자
            if (S[i] == '0')
                num0++;
            else
                num1++;
        }
    }

    cout << min(num0, num1) << '\n';
    
    return 0; 
}

