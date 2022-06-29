#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;

    long long two = 0, five = 0;
    cin >> n >> m;

    // nCm = n! / m!(n-m)!

    // >> 2
    // n!
    for (long long i=2; i<=n; i*=2)
        two += n/i;  

    // m!
    for (long long i=2; i<=m; i*=2)
        two -= m/i;
  
    // (n-m)!
    for (long long i=2; i<=(n-m); i*=2)
        two -= (n-m)/i;


    // >> 5 
    // n!
    for (long long i=5; i<=n; i*=5)
        five += n/i;  

    // m!
    for (long long i=5; i<=m; i*=5)
        five -= m/i;
  
    // (n-m)!
    for (long long i=5; i<=(n-m); i*=5)
        five -= (n-m)/i;

    cout << min(two, five) << '\n';
    return 0;
}