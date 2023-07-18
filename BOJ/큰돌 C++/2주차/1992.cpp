#include <iostream>
#include <string>

using namespace std;

const int SIZE = 64;

int N;
char map[SIZE][SIZE];


void Input()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }
}

string Quard(int y, int x, int size)
{
    if (size == 1) return string(1, map[y][x]);
    
    char ch = map[y][x];
    string result = "";
    for(int i=y; i<y+size; i++)
    {
        for(int j=x; j<x+size; j++)
        {
            if (ch != map[i][j])
            {
                result += '(';
                result += Quard(y, x, size/2);
                result += Quard(y, x+size/2, size/2);
                result += Quard(y+size/2, x, size/2);
                result += Quard(y+size/2, x+size/2, size/2);
                result += ')';

                return result;
            }
        }
    }

    return string(1, map[y][x]);

}

void Solve()
{
    cout << Quard(0, 0, N);
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