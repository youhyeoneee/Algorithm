#include <iostream>

using namespace std;


bool isPrime(int x){
    if (x==1)
        return false;

    for(int i=2; i<x; i++){
        if (x%i == 0)
            return false;
    }
    
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, result = 0;;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        if(isPrime(x))
            result++;
    }

    cout << result << '\n';

    return 0;
}