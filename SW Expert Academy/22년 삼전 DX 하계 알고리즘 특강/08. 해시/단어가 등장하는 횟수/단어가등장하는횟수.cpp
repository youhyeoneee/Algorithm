#include <iostream>
#include <string>

// 19 / 20 (제한시간 초과)
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    string B, S;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        // INIT 
        int result = 0;

        // INPUT
        cin >> B >> S;

        // PROCESS  
        for(int i=0; i<B.size(); i++){
            if (B[i] == S[0]){
                string str = B.substr(i, S.size());
                cout << str << "\n";
                if (str == S) result++;
            }
        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}