#include <iostream>

using namespace std;

int main()
{
    int N, M, i, j, temp;
    int arr[101];
    

    cin >> N >> M;

    for(int a=1; a<=N; a++) {
        arr[a] = a;
    }
    
    for(int a=1; a<=M; a++) {
        cin >> i >> j;
        
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }


    for(int a=1; a<=N; a++) {
        cout << arr[a] << " ";    
    }
    return 0;
}
