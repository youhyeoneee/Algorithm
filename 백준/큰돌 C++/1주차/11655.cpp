#include <iostream>
#include <string>

using namespace std;

string S;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, S);

}

void Solve()
{
    for(char s: S)
    {
        // 소문자 
        if ('a' <= s && s <= 'z')
        {
            if ((s + 13) <= 'z') cout << (char)(s+13);
            else cout << (char)(s-13);
        }
        else if ( 'A' <= s && s <= 'Z')
        {
            if ((s + 13) <= 'Z') cout << (char)(s+13);
            else cout << (char)(s-13);
        }
        else
            cout << s;
    }


}
int main()
{
    Input();
    Solve();
    return 0;
}