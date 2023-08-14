#include <iostream>
#include <string>

using namespace std;

int H, W;

void Input()
{
    cin >> H >> W;

}

void Solve()
{
    for(int i=0; i<H; i++)
    {
        string str;
        cin >> str;

        int lastC = -1;

        for(int j=0; j<str.size(); j++)
        {
            char ch = str[j];


            if (ch == 'c') 
            { 
                lastC = j;
                cout << 0 << " ";
            }
            else 
            {
                if (lastC == -1)
                    cout << -1 << " ";
                else
                    cout << j - lastC << " ";
            }
        }
        cout << '\n';            
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}