#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N;
    int num_arr[1000001];

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> num_arr[i];
    }

    sort(num_arr, num_arr+N);

    cout << num_arr[0] << " " << num_arr[N-1];
    return 0;
}