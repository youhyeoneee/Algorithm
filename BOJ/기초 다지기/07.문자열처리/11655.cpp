#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    getline(cin, S);
    string result = "";
    for(int i=0; i<S.length(); i++){
        char item = S[i];
        // 공백
        if (item == ' '){
            result += item;
        }
        // 숫자
        else if (item >= '0' && item <= '9'){
            result += item;
        }
        else if (item >= 'A' && item <= 'Z'){   
            if (item >= 'N'){
                result += (item - 13);
            }
            else
                result += (item + 13);
            
        }
        else if (item >= 'a' && item <= 'z'){
            if (item >= 'n'){
                result += (item - 13);
            }
            else
                result += (item + 13);
        }
    }

    cout << result << '\n';


    return 0;
}