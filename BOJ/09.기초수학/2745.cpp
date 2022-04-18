#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    int B, result = 0;
    cin >> N >> B;

    for(int i=0; i<N.length(); i++){
        int item = N[i];
        if ('A' <= item && item <= 'Z'){
            item = item - 55;
        }
        else{
            item = item - '0';
        }
        result += item*pow(B, N.length()-1-i);
    }
    
    cout << result << '\n';

    
    return 0;
}