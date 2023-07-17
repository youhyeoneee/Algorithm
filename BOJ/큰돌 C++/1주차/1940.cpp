#include <iostream>

using namespace std;

int N, M;
int arr[15001];

void Input()
{
    cin >> N;
    cin >> M;   

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    int cnt = 0;

    // 고유한 번호 최대 : 100000
    if (M <= 200000)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                if (arr[i] + arr[j] == M) cnt++;
            }
        }
    }
   
    cout << cnt;
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