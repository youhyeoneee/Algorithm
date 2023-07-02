#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkNesting(string s)
{
    int count = 0;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
            ++count;
        else if (ch == ')')
        {
            --count;
            if (count < 0)  return false;
        }
    }

    return count == 0;
}

int main()
{
    string str = "(()()";

    stack<char> ss;

    for(int i=0; i<str.length(); ++i)
    {
        if (i == 0)
            ss.push(str[i]);
        else 
        {
            if (str[i] == ')' && ss.top() == '(')
                ss.pop();
            else
                ss.push(str[i]);
        }

    }

    if (ss.size() == 0)
        cout << "YES\n";
    else 
        cout << "NO\n";

    cout << checkNesting(str);
    
    return 0;

}