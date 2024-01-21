#include <iostream>
#include <stack>
#include <string>

// 3:34 ~ 3:55 까지 고민 후 풀이 참고
// 3:58 ~ 4:08 다시 풀이 시작

using namespace std;

string str;
char left2 = '(';
char left3 = '[';
char right2 = ')';
char right3 = ']';

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isRightBlanket(string str) 
{

    stack<char> s;
    for(char ch : str) 
    {
        if (ch == left2 || ch == left3)
        {
            s.push(ch);
        }
        else if (ch == right2) 
        {
            if (!s.empty() && s.top() == left2)
            {
                s.pop();
            }
            else // 비어있거나 top이 left3이 아닌 경우 
            {
                s.push(ch);
            }
        }
        else if (ch == right3) 
        {
            if (!s.empty() && s.top() == left3)
            {
                s.pop();
            }
            else 
            {
                s.push(ch);
            }
        }
    }

    return s.empty();
}

int solve(string str) 
{
    if (!isRightBlanket(str))
    {
        return 0;
    }

    int result = 0;
    int temp = 1;

    for(int i=0; i<str.length(); i++)
    {
        char target = str[i];
        if (target == left2)
        {
            temp *= 2;
        }
        else if (target == left3) 
        {
            temp *= 3;
        }
        else if (target == right2)
        {
            if (str[i-1] == left2)
            {
                result += temp;
            }
            temp /= 2;
        }
        else if (target == right3)
        {
            if (str[i-1] == left3)
            {
                result += temp;
            }
            temp /= 3;
        }
        
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
