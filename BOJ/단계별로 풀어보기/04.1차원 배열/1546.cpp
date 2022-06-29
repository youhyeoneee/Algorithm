#include <iostream>

using namespace std;

int main(){

    int N, max = 0;
    double arr[1001];
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
        if (arr[i]>max) max = arr[i];
    }


    double result = 0;
    for(int i=0; i<N; i++)
        result += arr[i]/max*100;

    cout << result/N << '\n';

    return 0;
}