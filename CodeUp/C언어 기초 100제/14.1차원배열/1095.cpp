#include <iostream>

using namespace std;

int main(){

    int n, k;
    int arr[10001] = {0, };
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> k;
        arr[k]+=1;
    }
    
     for (int i=1; i<=n; i++){
         if (arr[i] != 0){
            cout << i << '\n';
            break;
         }
     }
    return 0;
}