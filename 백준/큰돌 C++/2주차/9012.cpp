#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
string str;

void Solve()
{
    stack<char> s;

    for(char ch : str)
    {
        if (!s.empty())
        {
            char top = s.top();
            if (top == '(' && ch == ')')
                s.pop();
            else
                s.push(ch);
        }
        else
            s.push(ch);
    }

    if (s.empty()) cout << "YES\n";
    else cout << "NO\n";

}

void Input()
{
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> str;
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