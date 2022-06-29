#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int N, K;
    cin >> N >> K;
    int arr[N];

    for (int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    cout << arr[K-1] << '\n';

    return 0;

}