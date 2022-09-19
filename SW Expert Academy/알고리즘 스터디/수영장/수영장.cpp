#include <iostream>
#include <string.h>
#include <algorithm>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result;
int plan[13], price[4];
int dp[13];

void Init(){
    result = 0;
    memset(dp, 0, sizeof dp);
}

void Input(){
    // 1일 이용권의 요금, 1달 이용권의 요금, 3달 이용권의 요금, 1년 이용권의 요금
    for(int i=0; i<4; i++){
        cin >> price[i];
    }
    for(int i=1; i<=12; i++){
        cin >> plan[i];
    }
}

void Solve(){
    int day = price[0];  
    int month = price[1]; 
    int three_month = price[2];
    int year = price[3];

    // 1월
    dp[1] =  min(day * plan[1], month); // 1일 VS 1달
    
    // 1~2월
    dp[2] = dp[1] + min(day * plan[2], month); // 1일 VS 1달

    // 1~i월
    for(int i=3; i<=12; i++){
        // 1일 VS 1달 VS 3달
        dp[i] = min({dp[i-1] + (day * plan[i]), dp[i-1] + month, dp[i-3] + three_month});
    }


    result = min(dp[12], year); // 1년이 제일 쌀 경우
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		Init();
        Input();
        Solve();
        cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}