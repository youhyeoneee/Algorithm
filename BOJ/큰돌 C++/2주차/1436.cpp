#include <iostream>
#include <string>

using namespace std;

int N;
void Input()
{
    cin >> N;
}

void Solve()
{
    int i=1;
    long long num = 666;
    while(i < N)
    {
        num++;
        if (to_string(num).find("666") != string::npos) i++;
    }

    cout << num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}