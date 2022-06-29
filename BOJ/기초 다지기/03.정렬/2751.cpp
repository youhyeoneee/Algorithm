#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N; // 수의 개수 N
    cin >> N;

    int a[N+1] = {0, };// 수열

    a[0] = 0;

    // 입력
    for(int i=0; i<N; i++)
        cin >> a[i];
 
    // Quick Sort
    sort(a, a+N);

    // 출력 
    for(int i=0; i<N; i++)
        cout << a[i] << '\n';

    return 0;
}