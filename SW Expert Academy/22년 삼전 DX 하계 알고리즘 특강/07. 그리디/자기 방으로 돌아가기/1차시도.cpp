#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


// 2/10 (오답)

int arr[401];

int main(int argc, char** argv)
{
	int test_case;
	int T, N, result, s, e;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   

        // INIT
        memset(arr, 0, sizeof arr);
        result = 0;

        // INPUT
        // 돌아가야 할 학생들의 수 N
        cin >> N;

        for(int i=0; i<N; i++){
            // 각 학생의 현재 방 번호(≤400)와 돌아가야 할 방의 번호
            cin >> s >> e;

            for(int j=s; j<=e; j++)
                arr[j]++;
        }


        // OUTPUT
        cout << "#" << test_case << " " << *max_element(arr , arr + 401)<< "\n";


	}
	return 0;
}