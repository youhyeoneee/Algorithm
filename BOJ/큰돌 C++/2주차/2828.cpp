#include <iostream>

using namespace std;

int N, M, J;



void Input()
{
    cin >> N >> M;
    cin >> J;
}

void Solve()
{
    int pos;
    int start = 1;
    int end = M;
    int result = 0;
    for(int i=0; i<J; i++)
    {
        cin >> pos;

        if (start <= pos && pos <= end) 
            continue;
        else if (pos < start) // 왼쪽으로 이동
        {
            int offset = start - pos;
            result += offset;
            start -= offset;
            end -= offset;
        }
        else if (end < pos) // 오른쪽으로 이동
        {
            int offset = pos - end;
            result += offset;
            start += offset;
            end += offset;
        }
    }

    cout << result;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}