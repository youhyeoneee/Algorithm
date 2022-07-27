#include <iostream>
#include <algorithm>


// N과 M (9)
using namespace std;

int N, M;
int arr[8];
int can_use[10001] = {0, };
int ans[8];
bool is_print = false;

void search(int n){
    if (n == M){
        cout << ans[0];
        for (int i=1; i<M; i++)
            cout << " " << ans[i];
        cout << '\n';
        is_print = true;
        return;
    }

    for (int i=0; i<N; i++){
        if((i==0 || arr[i-1] != arr[i]) &&can_use[arr[i]]){
            ans[n] = arr[i];
            can_use[arr[i]]--;
            search(n+1);
            can_use[arr[i]]++;

        }
    }

    return;
}
int main(){

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
        can_use[arr[i]]++;
    }
    
    sort(arr, arr+N);
    search(0);

    return 0;
}