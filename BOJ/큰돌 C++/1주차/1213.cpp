#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
int cnt[200];

void Input()
{
    cin >> str;
}

void Solve()
{
    map<char, int> _map;

    for(char ch : str)
    {
        _map[ch]++;
    }

    int cnt = 0; 
    char key;

    for(auto c : _map)
    {
        if (c.second % 2 == 1)
        { 
            cnt++;
            key = c.first;
        }
    }

    // 홀수가 2개 이상이면 불가능
    if (cnt > 1) cout << "I'm Sorry Hansoo";
    else 
    {
        // 가운데에 올 것
        _map[key]--;
        
        string pallStr;
        for(auto c : _map)
        {
            for(int i=0; i<(c.second/2); i++)
            {
                pallStr += c.first;
            }
        }
        cout << pallStr; 
        
        if (cnt == 1)
            cout << key;

        for(int i=pallStr.length()-1; i>=0; --i)
        {
            cout << pallStr[i];
        }
    }
}

// 큰돌님 풀이
void Solve2()
{
    for(char ch: str) cnt[ch]++;
    char mid;
    int flag = 0;
    string result;

    for(int i='Z'; i>='A'; i--)
    {
        if (cnt[i])
        {
            // 홀수인 경우
            if (cnt[i] & 1)
            {
                mid = char(i);
                flag++;
                cnt[i]--;
            }  

            if (flag == 2) break;

            for(int j=0; j<cnt[i]; j+=2)
            {
                // 앞에 붙이고 뒤에 붙이기
                result = char(i) + result;
                result += char(i);
            }
        }
    }

    // 중간 문자 삽입
    if (mid) result.insert(result.begin() + result.size() / 2, mid);

    // 출력 
    if (flag == 2) cout << "I'm Sorry Hansoo";
    else cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    // Solve();
    Solve2();
}