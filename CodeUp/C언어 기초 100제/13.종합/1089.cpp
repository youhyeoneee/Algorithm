#include <iostream>

using namespace std;

int main(){

    int a, d, n;
    cin >> a >> d >> n;
    
    // cout << (a+(d*(n-1))) << '\n';

    for (int i=1; i<n; i++){
        a+=d;
    }

    cout << a << '\n';
    return 0;
}