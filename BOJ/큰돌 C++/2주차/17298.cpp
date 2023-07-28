#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int N;
int arr[1000004];
int NGE[1000004];

void Input()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    stack<int> s;

    memset(NGE, -1, sizeof(NGE));

    for(int i=0; i<N; i++)
    {
        while(s.size() && arr[s.top()] < arr[i])
        {
            NGE[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }    

    for(int i=0; i<N; i++)
    {
        cout << NGE[i] << ' ';
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