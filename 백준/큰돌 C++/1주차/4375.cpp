#include <iostream>

using namespace std;
typedef long long ll;

int N;

void Solve()
{
    bool find = false;

    ll result = 1;
    ll cnt = 1;

    while(result % N != 0)
    {   
        result = (result * 10) % N + 1; // 1%N == 1
        cnt++;
    }

    cout << cnt << '\n';

}

void Input()
{
    while(cin >> N)
    {
        Solve();
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    return 0;
}