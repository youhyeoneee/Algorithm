#include <iostream>
#include <string>
#include <stack>

using namespace std;


string str;

void Remove(stack<char> &s, char ch, bool isBig)
{
    char left, right;

    if (isBig)
    {
        left = '[';
        right = ']';
    }
    else
    {
        left = '(';
        right = ')'; 
    }

    if (!s.empty())
    {
        char top = s.top();
        if (ch == right && top == left)
            s.pop();
        else 
            s.push(ch);
    }
    else s.push(ch);
}


void Solve()
{

    stack<char> sSmall; // 소괄호 
    stack<char> sBig; // 대괄호 

    for(char ch : str)
    {
        if (ch == '(' || ch == ')')
            Remove(sSmall, ch, false);
        else if (ch == '[' || ch == ']')
            Remove(sSmall, ch, true);
    }

    if (sSmall.empty() && sBig.empty()) cout << "yes\n";
    else cout << "no\n";
}   

void Input()
{
    while(true)
    {
        getline(cin, str);
        if (str == ".") break;
        Solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
}