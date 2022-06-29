#include <iostream>

using namespace std;

int factorization(int n){
    for(int i=2; i<=n; i++){
        if (n % i == 0){
            cout << i << '\n';
            return n/i;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
    
    if(N != 1){
        while(N>0){
            N = factorization(N);
        }
        
    }
    return 0;
}