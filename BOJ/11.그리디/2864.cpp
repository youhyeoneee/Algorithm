#include <iostream>
#include <string>

// 브론즈2

using namespace std;

int change(bool min_or_max, string str) { // 0이면 min 1이면 max
    if(min_or_max){ // 최대
        for(int i=0; i<str.size(); i++){
            if (str[i] == '5'){
                str[i] = '6';
            }
        }
    }   
    else{ // 최소
        for(int i=0; i<str.size(); i++){
            if (str[i] == '6')
                str[i] = '5';
        }
    }
    return stoi(str);
}

int main(){
    
    string A, B;

    cin >> A >> B;

    // 최소
    cout << change(0, A) + change(0, B) << '\n';
    // 최대
    cout << change(1, A) + change(1, B) << '\n';

    return 0;
}