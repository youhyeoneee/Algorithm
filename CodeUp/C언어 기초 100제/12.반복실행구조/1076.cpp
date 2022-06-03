#include <iostream>

using namespace std;

int main(){

    char n, a = 'a';
    cin >> n;

    do{
        cout << a << ' ';
        a++;
    }while(a<=n);
    
    return 0;
}