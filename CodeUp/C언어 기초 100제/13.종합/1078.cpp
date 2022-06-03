#include <iostream>

using namespace std;

int main(){

    int n, sum = 0;
    cin >> n;

    for (int i=1; i<=n; i++){
        if (i%2 == 0)
            sum+=i;
    }
    
    cout << sum << '\n';
    return 0;
}