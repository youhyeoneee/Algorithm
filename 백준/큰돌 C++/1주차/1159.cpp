#include <iostream>
#include <string>
#define SIZE 26

using namespace std;

int arr[SIZE];
int N;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 선수의 수 
    cin >> N;    
}

void Solve()
{
    for(int i=0; i<N; i++)
    {
        string name;
        cin >> name;
        
        arr[name[0] - 'a']++;
    }

    bool isPREDAJA = true;
    for(int i=0; i<SIZE; i++)
    {
        if (arr[i] >= 5)
        {            
            cout << (char)(i+'a');
            isPREDAJA = false;
        }
    }

    if (isPREDAJA) cout << "PREDAJA";
}

int main()
{
    Input();
    Solve();
    return 0;
}