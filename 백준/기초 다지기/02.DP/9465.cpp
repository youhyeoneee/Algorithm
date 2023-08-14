#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int T, n;

    cin >> T; // 테스트 케이스

    for (int i=0; i<T; i++){

        cin >> n; // 스티커 열 개수 입력 받기

        int sticker[2][n+1] = {0,}; // 각 숫자를 골랐을 때 최대 점수 
        int dp[2][n+1] = {0,}; // 각 숫자를 골랐을 때 최대 점수 

        for (int j=0; j<2; j++) // 스티커 점수 배열 입력 받기
            for(int k=1; k<=n; k++)
                cin >> sticker[j][k]; 

        dp[0][0] = dp[1][0] = 0; // 0번째 칸 초기화

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
    
        // 각 칸을 선택 했을 때, 1번째 대각선 전의 점수와 2번 대각선 전의 점수를 비교하여 최댓값을 더함
        
        for(int i=2; i<=n; i++){
            dp[0][i] = max(dp[1][i-2], dp[1][i-1]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-2], dp[0][i-1]) + sticker[1][i];
        }
        int score = max(dp[0][n], dp[1][n]); // 점수

        cout << score << endl;
    }
    
    return 0;
}