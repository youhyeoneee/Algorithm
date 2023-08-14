#include <iostream>
#include <algorithm>

 using namespace std;

 int main(){

    int n;

    cin >> n;

    int a[n+1] = {0, };
    for (int i=1; i<=n; i++)
        cin >> a[i];

    int dp[n+1] = {0, };

    dp[1] = a[1];

    for(int i=2; i<=n; i++){
        dp[i] = max(a[i], dp[i-1]+a[i]);
    }

    int result = dp[1];
    for(int i=2; i<=n; i++)
    {
        if(result < dp[i])
            result = dp[i];
    }

    cout << result << endl;

    return 0;
 }