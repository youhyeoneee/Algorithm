#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solve(string str) 
{
    stack<char> s;
    char left = '(';
    char right = ')';

    int pipeCnt = 0;
    int result = 0;

    for(char ch : str) 
    {      

        if (ch == left) 
        {
            pipeCnt++;
        }
        else if (ch == right)
        {
            if (s.top() == left) // 레이저
            {
                result += --pipeCnt;
            }
            else if (s.top() == right) // 쇠막대기
            {
                pipeCnt--;
                result++;
            }
        }

        s.push(ch);
    }

    return result;
}

void output(string str)
{
    cout << solve(str) << '\n';
}

void input() 
{
    cin >> str;
    output(str);
}

int main() 
{
    fastIO();
    input();

    return 0;
}
