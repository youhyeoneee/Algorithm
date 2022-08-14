#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N, K;

    // 1~최대 100번 
    // 가방 최대 부피 : 1000
    int dp[101][1001];
    int V[101], C[101]; // 부피, 가치
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   

        // INPUT

        // 가방의 부피인 N K
        cin >> N >> K;

        for(int i=1; i<=N; i++){
            // 물건의 정보를 나타내는 부피  Vi 와 가치 Ci
            cin >> V[i] >> C[i];
        }

        
        // INIT
        memset(dp, 0, sizeof dp);

        // 개수 증가하면서
        for(int i=1; i<=N; i++){
            // 무게 증가하면서
            for(int w=1; w<=K; w++){
                // i번째 보석이 w보다 무거울 때
                if (V[i] > w) dp[i][w] = dp[i-1][w];
                else {

                    // i번째 보석을 포함했을 때
                    dp[i][w] = max(C[i] + dp[i-1][w-V[i]], dp[i-1][w]);
                }
            }
        }

        cout << "#" << test_case << " " << dp[N][K] << "\n";

	}
	return 0;
}