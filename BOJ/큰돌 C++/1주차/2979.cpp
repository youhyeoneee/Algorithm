#include <iostream>

using namespace std;

int A, B, C;
int arr[101];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
}

void Solve()
{
    for(int i=0; i<3; i++)
    {
        int start, end;
        cin >> start >> end;

        for(int i=start; i<end; i++) arr[i]++;
    }

    int sum = 0;
    for(int a : arr)
    {
        switch (a)
        {
            case 1:
                sum += A;
                break;
            case 2:
                sum += 2 * B;
                break;
            case 3:
                sum += 3 * C;
                break;    
            default:
                break;
        }
    }

    cout << sum;
}


int main()
{
    Input();
    Solve();

    return 0;
}