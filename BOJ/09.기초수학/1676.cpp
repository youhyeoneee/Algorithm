#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);6

    int ans = 0;

    int N;
    cin >> N;

    for (int i=5; i<=N; i*=5)
        ans += N/i;
    cout << ans << '\n';
  
    return 0;
}