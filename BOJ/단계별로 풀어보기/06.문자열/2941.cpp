#include <iostream>
#include <string>

using namespace std;

int main(){ 

    string str;
    cin >> str;

    int result = str.length();

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(i != str.length()-1){ // 마지막 글자가 아니라면
            char next = str[i+1];

            if(ch == 'c'){ // c= , c-
                if (next == '=' || next == '-') result--; 
            }
            else if(ch == 'd'){ // d-
                if (next == '-') result--; 
            }
        }

        if (i != 0){ // 첫번째 글자가 아니라면
            char before1 = str[i-1];

            if(ch == 'j'){ // lj, nj
                if (before1 == 'l' || before1 == 'n') result--;
            }
            else if(ch == '='){ // lj, nj
                if (before1 == 's') result--;
                else if (i>=2){
                    char before2 = str[i-2];
                    if (before2 == 'd' && before1 == 'z') result-=2; // dz=
                    else if (before1 == 'z') result--; // z=
                }
                else if (before1 == 'z') result--; // z=
            }
        }
        

    }

    cout << result;
    return 0;
}