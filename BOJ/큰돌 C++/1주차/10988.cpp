#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
}

void Solve()
{
    bool isPalindrome = true;
    for(int i=0, j=S.length()-1; i<S.length(); i++, j--)
    {
        if (S[i] != S[j])
        {
            isPalindrome = false;
            break;
        }
    }

    cout << isPalindrome;
}

void Solve2()
{
    string temp = S;
    reverse(temp.begin(), temp.end());

    cout << (temp == S);
}

int main()
{
    Input();
    Solve();
    Solve2();
    return 0;
}