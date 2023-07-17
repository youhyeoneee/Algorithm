#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string str;
int cnt = 0;

void Solve()
{
    stack<char> _stack;

    for(char ch: str)
    {
        // 넣으려는 게 같은 경우 제거
        if (_stack.size() && _stack.top() == ch) _stack.pop();
        else _stack.push(ch);
    }

    if (_stack.empty()) cnt++;
}

void Input()
{
    cin >> N;


    for(int i=0; i<N; i++)
    {
        cin >> str;
        Solve();
    }

    cout << cnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();

}