#include <iostream>

using namespace std;

int A, B;

void solve()
{
    if (A > B)
    {
        if (A % B == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
    else // A < B 
    {        
        if (B % A == 0) cout << "factor\n";
        else cout << "neither\n";

    }
}

int main()
{
    while(true)
    {
        cin >> A >> B;

        if (A > 0 && B > 0) solve();
        else break;

    } 

}