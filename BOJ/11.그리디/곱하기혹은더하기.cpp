#include <iostream>
#include <string>

using namespace std;

int main(){

    string S;
    cin >> S;

    long long result = S[0] - '0';

    if (S.length()>1){
        for(int i=1; i<S.length(); i++){
            int temp = S[i] - '0';
            // 1보다
            if (temp >1 && result>1)
                result *= temp;
            else // 0이나 1이면 더하기
                result += temp;
        }
    }
   
    cout << result << '\n';


    return 0;

}