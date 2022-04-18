#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

void trans(int n){

    if (n == 0)
        return;

    // 경우 1. 2로 나눠지는 경우
    if (n % 2 == 0){
        trans(-(n/2));
        cout << 0;
    }
    else{
        // 경우 2-1. 2로 나눠지지 않는 경우 + 양수 인 경우 
        if(n > 0) 
            trans(-(n / 2)); 
        // 경우 2-2. 2로 나눠지지 않는 경우 + 음수 인 경우 
        else 
            trans((-n + 1) / 2);
        cout << 1;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 0)
        cout << 0;
    else   
        trans(N);
    
    cout << '\n';

    return 0;
}