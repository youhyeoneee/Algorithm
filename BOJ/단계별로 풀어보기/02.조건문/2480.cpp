#include <iostream>
#include <algorithm> 

using namespace std;

int main(){

    int arr[3];

    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr+3);

    // 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다. 
    if (arr[0] == arr[1] && arr[1] == arr[2]) cout << 10000+(arr[0]*1000);
    // 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다. 
    else if (arr[0] == arr[1] || arr[1] == arr[2])  cout << 1000+(arr[1]*100);
    // 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.  
    else cout << arr[2]*100;

    return 0;
}