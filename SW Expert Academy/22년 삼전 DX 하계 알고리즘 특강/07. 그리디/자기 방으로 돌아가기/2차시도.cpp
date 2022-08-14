#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


// 2/10 (오답)

int main(int argc, char** argv)
{
	int test_case;
	int T, N, result, before_s, before_e, s, e;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   

        // INIT
        result = 1;

        // INPUT
        // 돌아가야 할 학생들의 수 N
        cin >> N;

        cin >> before_s >> before_e;

        for(int i=1; i<N; i++){
            // 각 학생의 현재 방 번호(≤400)와 돌아가야 할 방의 번호
            cin >> s >> e;

            if(before_s < s && s < before_e) result++;

            before_s = s;
            before_e = e; 
            
        }


        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";


	}
	return 0;
}