#include <iostream>

using namespace std;

int factorial(int n){
    int result = 1;
    
    for(int i=1; i<=n; i++){
        result *= i;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    cout << factorial(N) << '\n';
    return 0;
}