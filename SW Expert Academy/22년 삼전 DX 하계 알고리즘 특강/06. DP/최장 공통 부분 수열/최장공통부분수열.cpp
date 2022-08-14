#include <iostream>
#include <string.h>
#include <algorithm>

#define MAX 1001

using namespace std;

string a, b; // 각 문자열의 길이는 1,000 이하의 자연수

int dp[MAX][MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int result;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        // INPUT
        cin >> a >> b;

        // INIT
        memset(dp, 0, sizeof dp);
        result = 0;

        int a_size = a.length();
        int b_size = b.length();

        for(int i=1; i<=a_size; i++){
            for(int j=1; j<=b_size; j++){
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
        // OUTPUT
        cout << "#" << test_case << " " << dp[a_size][b_size] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}