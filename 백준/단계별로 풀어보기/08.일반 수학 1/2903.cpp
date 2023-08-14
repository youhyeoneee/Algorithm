#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N;

    cin >> N;

    long long dot = 2;

     // 0 -> 2^2 
    // (2+1) 
    // 1 -> 3^2 
    // (3 + 2)
    // 2 -> 5^2; 
    // (5 + 4)
    // 3 -> 9^2; 
    // (9 + 8)
    // 4 -> 17^2 
    // (17 + 16);
    // 5 -> 33^2 +16
    
    for(int i=0; i<N; i++)
    {
          
        dot = dot + dot -1;
    }

    cout << (long long)pow(dot, 2) << '\n';
}