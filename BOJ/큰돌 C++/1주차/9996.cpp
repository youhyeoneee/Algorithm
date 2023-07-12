#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string pattern;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> pattern;
}

void Solve()
{
    
    int pos = pattern.find('*');
    string prefix = pattern.substr(0, pos);
    string subfix = pattern.substr(pos+1);

    for(int i=0; i<N; i++)
    {
        string S;
        cin >> S;

        if (prefix.size() + subfix.size() > S.size())
            cout << "NE\n";
        else 
        {
            if (prefix == S.substr(0, pos) && subfix == S.substr(S.size() - subfix.size()))
                cout << "DA\n";
            else cout << "NE\n";

        }
       
    }
}

int main()
{
    Input();
    Solve();

    return 0;
}