#include <iostream>
#include <string>
#define SIZE 26
using namespace std;

string S;
int arr[SIZE]; // 전역변수로 하면 0으로 초기화 됨

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
}

void Solve()
{
    // a -> 97 = 0
    // z -> 122 = 25
    for(char i : S)
        arr[i - 'a']++; 
    
    for(int i=0; i<SIZE; i++)
        cout << arr[i] << " ";
}

int main()
{
    Input();
    Solve();
    return 0;
}