#include <iostream>
#include <string>

using namespace std;

string S;
int offset = 'a' - 'A';

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S;
}

void Solve()
{
    for(char ch : S)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            cout << (char)(ch + offset);
        }
        else if ('a' <= ch && ch <= 'z')
        {
            cout << (char)(ch - offset);
        }
    }
}

int main()
{

    Input();
    Solve();

    return 0;
}