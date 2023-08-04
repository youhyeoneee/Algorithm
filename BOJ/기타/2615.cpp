#include <iostream>
#include <vector>

#define BLACK 1
#define WHITE 2
#define DEBUG(X) //cout << X;
using namespace std;

const int N = 19;

int arr[N+4][N+4];

int dy[] = {0, 1, 1, -1}; // 오른쪽, 아래, 오아, 오위 대각선만 검사
int dx[] = {1, 0, 1, 1};

void Input()
{
    for(int i=0; i<N; i++)
    {   
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    return;
}


bool IsOmok(int color, int y, int x, int dir, int cnt)
{
    for(; color == arr[y][x]; cnt++)
    {
        y += dy[dir]; 
        x += dx[dir];
    }
    
    return (cnt == 5);
}

void Solve()
{   
    for(int i=0; i<N; i++)
    {   
        for(int j=0; j<N; j++)
        {
            if (arr[i][j] != 0)
            {
                for(int dir=0; dir<4; dir++)
                {
                    if (IsOmok(arr[i][j], i, j, dir, 0))
                    {
                        int by = i - dy[dir];
                        int bx = j - dx[dir];


                        // 범위 안이면 검사 
                        if (by >= 0 || by < N || bx >= 0 || bx < N)
                        {
                            // 6목 X
                            if (arr[by][bx] != arr[i][j]) 
                            {
                                cout << arr[i][j] << '\n' << i+1 << ' ' << j+1 << '\n';
                                return;
                            }
                        }
                        else 
                        {
                            cout << arr[i][j] << '\n' << i+1 << ' ' << j+1 << '\n';
                            return;
                        }
                    }

                }
            }
        }
    }

    cout << '0';
    
    return;
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