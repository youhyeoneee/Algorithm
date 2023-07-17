#include <iostream>

using namespace std;
typedef long long ll;

ll A, B, C;

void Input()
{
    cin >> A >> B >> C;
}

int Go(ll a, ll b)
{
    // 기저 사례
    if (b == 1) return a % C;

    ll result = Go(a, b/2); 

    result = (result * result) % C;

    // 홀수는 한번 더 해줘야 함
    if (b % 2) result = (result * a) % C;

    return result;
}
void Solve()
{
    cout << Go(A, B);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}