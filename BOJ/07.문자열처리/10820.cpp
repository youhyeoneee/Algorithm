#include <iostream>
#include <string>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;

    while (getline(cin, S))
    {
        int num[4] = {0, }; // 소문자, 대문자, 숫자, 공백의 개수
        for (int j=0; j<S.length(); j++){
            char c = S[j];
            // 소문자 ?
            if (c >= 'a' && c <= 'z')  
                num[0]++;
            // 대문자 ?
            else if (c >= 'A' && c <= 'Z')
                num[1]++;
            // 숫자 ?
            else if (c >= '0' && c <= '9')
                num[2]++;
            //공백 ?
            else if (c == ' ')
                num[3]++;    
        }

        for (int j=0; j<4; j++){
            cout << num[j] << ' ';
        }
        cout << '\n';
            
    }

    return 0;
}