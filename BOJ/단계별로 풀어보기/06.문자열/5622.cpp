#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;
    int result = 0;

    cin >> str;

    // 65 ~ 90

    int num;
    for(char ch : str){
        result+=2;
        
        // PQRS = 7
        if ((int)ch <83) num = (((int)ch - 59)/3);  
        else num = (((int)ch - 60)/3);

        // WXYZ = 9
        if (num == 10) num--;
        result+=(num-1);
    }

    cout << result;
    return 0;
}