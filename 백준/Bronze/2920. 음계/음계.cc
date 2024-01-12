#include <iostream>
#include <string>

#define SIZE 8

using namespace std;

int arr[SIZE];

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void Input()
{  
    for(int i=0; i<SIZE; i++) 
    {
        cin >> arr[i];
    }

}

string Solve()
{
    string result;

    if (arr[0] < arr[1])
    {
        result = "ascending";
    }
    else 
    {
        result = "descending";
    }

    for(int i=1; i<SIZE-1; i++)
    {
        if (result == "ascending") 
        {
            if (arr[i] > arr[i+1])
            {
                result = "mixed";
                return result;
            }
        }
        else if (result == "descending")
        {
            if (arr[i] < arr[i+1])
            {
                result = "mixed";
                return result;
            }
        }
    }

    return result;
}

void Output()
{
    cout << Solve();
}

int main()
{
    FastIO();
    Input();
    Output();
}