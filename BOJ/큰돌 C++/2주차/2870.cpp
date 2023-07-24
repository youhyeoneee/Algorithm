#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<string> v;


void Input()
{
    cin >> N;
}   

// 자릿수 적은게 앞 
bool compare(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return (a.size() < b.size());
}

// 101 같은 case
string RemoveZero(string str)
{  
    int newIdx = 0;
    
    while(true)
    {
        if (str.size() && str.front() == '0')
            str.erase(str.begin()); 
        else 
            break;
    }

    if (str.size() == 0) return "0";
    else return str;
}


void Solve()
{
    string str;


    for(int i=0; i<N; i++)
    {
        cin >> str;

        string subS = "";

        for(char ch : str)
        {
            if ('a' <= ch && ch <= 'z')
            {
                if (subS.size() > 0)
                {
                    v.push_back(RemoveZero(subS));
                }
                
                subS = "";
            }
            else 
            {
                subS.push_back(ch);
            }
        }

        if (subS.size() > 0)
            v.push_back(RemoveZero(subS));
    }

    sort(v.begin(), v.end(), compare);

    for(string i : v)
    {
        cout << i << '\n';
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