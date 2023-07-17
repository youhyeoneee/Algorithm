#include <iostream>
#include <map>
#include <string>

using namespace std;

int TC;

void Solve()
{
    map<string, int> _map;
    int cnt;
    cin >> cnt;

    for (int i=0; i<cnt; i++)
    {
        string name, kind;
        cin >> name >> kind;
        _map[kind]++;
    }

    int sum = 1;
    // 각 종류의 개수 + 1 (입지 않았을 경우)를 모두 곱한 후 아무것도 안입은 경우의 수 1 을 뺀다
    for(auto c : _map)
    {
        sum *= c.second + 1;
    }
    cout << sum - 1 << '\n';
}

void Input()
{
    cin >> TC;

    for(int i=0; i<TC; i++)
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