#include <iostream>

using namespace std;

int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};


int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        // INPUT

        cin >> N;
        // 손님에게 거슬러 주어야 할 금액 N
        // N의 마지막 자릿수는 항상 0이다. (ex : 32850)


        cout << "#" << test_case << "\n";

        for(int i=0; i<8; i++){
            int m = money[i];
            int cnt = 0;

            while (m <= N){
                cnt++;
                N-= m;

            }
            cout << cnt << " ";
        }

        cout << "\n";
	}
	return 0;
}