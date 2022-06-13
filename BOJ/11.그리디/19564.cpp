#include <iostream>
#include <string>


// 브론즈 1

using namespace std;

int main(){

    string S;
    cin >> S;

    int K = 0, temp;
    for (int i=0; i<=S.size(); i++){
        if (i==0) //  처음꺼 저장
            temp = S[0];
        else{
            if (temp >= S[i])
                K++;
            temp = S[i];

        }

    }
    cout <<  K << '\n';
    return 0;
}