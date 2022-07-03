#include <iostream>

using namespace std;

int main(){

    int X, sum = 0, cnt = 0;

    cin >> X;

    for(; ; cnt++){
        sum += cnt;
        if (X <= sum) break;
    }

    int idx = (sum-X)+1;

    if (cnt % 2 == 1) cout << idx << '/' << cnt+1-idx << '\n'; // 홀수면 
    else cout << cnt+1-idx << '/' << idx << '\n';
    return 0;
}