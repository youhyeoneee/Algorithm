#include <iostream>
#include <string>


using namespace std;

// 실버2

int main(){

    string str;

    int result = 0;

    cin >> str;

    
    string num;
    int cnt = 0; // 연산자 카운트 

    bool minus = false;    
    for(int i=0; i<str.size(); i++){
        if (str[i] == '+' || str[i] == '-'){ 
            if(minus)   
                result -= stoi(num);
            else if (cnt == 0){  // 맨 처음 숫자
                result += stoi(num);
                num = "";
                cnt++;
            }
            else
                result += stoi(num);
            num = "";
            if(str[i] == '-')
                minus = true;
        }
        else{ // 숫자일 경우
            num += str[i];
        }
    }

    // 마지막 한번 더 해주기
    if(minus)
        result -= stoi(num);
    else
        result += stoi(num);

    cout << result << '\n';

    
    return 0;
}