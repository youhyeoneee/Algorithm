#include <iostream>
#include <math.h>

using namespace std;

long long sum = 0;
int temp;
int result = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<5; i++)
    {
        cin >> temp;
        sum += pow(temp, 2);
    }

    cout << sum % 10;
}