#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;
    int i=0, len = N.length();
    
    if (len % 3 == 1){
        cout << N[0];
        i = 1;
    }
    else if (len % 3 == 2){
        cout << (N[0]-'0')*2 + (N[1]-'0');
        i = 2;
    }
    for(; i<len; i+=3){
        cout << (N[i] - '0')* 4 + (N[i+1] - '0')*2 + (N[i+2] - '0');
    }
    cout << '\n';
    return 0;
}