#include <iostream>

using namespace std;

int main()
{
    long long result = 0;
    int temp;

    for(int i=0; i<5; i++)
    {
        cin >> temp;
        result += temp;
    }

    cout << result;
}