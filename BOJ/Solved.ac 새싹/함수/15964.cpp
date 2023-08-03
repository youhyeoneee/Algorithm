#include <iostream>

using namespace std;

long long A, B;
void Input()
{   
    cin >> A >> B;
}

void Solve()
{
    cout << (A+B)*(A-B);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}