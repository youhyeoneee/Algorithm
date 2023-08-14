#include <iostream>
#include <string>
#include <map>

#define MAX 100000

using namespace std;

int N, M;
string arr[MAX + 1];
map<string, int> stringMap;

void Input()
{
    cin >> N >> M;

    for(int i=1; i<=N; i++)
    {
        cin >> arr[i];
        stringMap[arr[i]] = i;
    }

}


void Solve()
{
    string input;
    for(int i=0; i<M; i++)
    {
        cin >> input;

        int idx = atoi(input.c_str());

        // 문자열일 경우
        if (idx == 0)
        {
            cout << stringMap[input] << '\n';
        }
        else // 숫자일 경우
        {
            cout << arr[idx] << '\n';
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    return 0;
}