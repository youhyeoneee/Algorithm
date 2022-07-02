#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;
    int cnt = 1;
    
    getline(cin, str);


    if (str[0] == ' ') cnt = 0;
    
    for (char ch : str)
        if(ch == ' ') cnt ++;

    if (str[str.length()-1] == ' ') cnt--;

    cout << cnt;

    return 0;
}