#include <iostream>

using namespace std;

long long N;
int T;

void Solve()
{
    int cnt2 = 0;
    int cnt5 = 0;

    for(int i=2; i<=N; i*=2)
    {
        cnt2 += (N / i);
    }

    for(int i=5; i<=N; i*=5)
    {
        cnt5 += (N / i);
    }

    cout << min(cnt2, cnt5) << "\n";
}

void Input()
{
    cin >> T;

    for(int i=0; i<T; i++)
    {
        cin >> N;
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