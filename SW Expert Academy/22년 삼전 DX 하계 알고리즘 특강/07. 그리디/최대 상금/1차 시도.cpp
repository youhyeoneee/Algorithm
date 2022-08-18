#include <iostream>
#include <string>
#include <algorithm>

// 11 / 15 (오답)

// 반례 )
// 1 
// 21 1 -> 0 

using namespace std;

int test_case;
int T, N;
string num;
int result = 0;

void dfs(int idx, int change){

    if (change == N){
        result = max(result, stoi(num));
        return;
    }
    else{
        for(int i=idx; i<num.length(); i++){
            for(int j=i+1; j<num.length(); j++){
                if (num[j] >= num[i]){
                    swap(num[i], num[j]);
                    dfs(i, change+1);
                    swap(num[i], num[j]);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        
        // INPUT
        cin >> num >> N;

        // INIT 
        result = 0;

        // PROCESS
        dfs(0, 0);

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}