#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> str_set;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;
    int result;
    string str;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        // INPUT
        cin >> N >> M;

        for(int i=0; i<N; i++){
            cin >> str;
            str_set.insert(str);
        }

        for(int i=0; i<M; i++){
            cin >> str;
            str_set.insert(str);
        }

        // PROCESS  
        result = (N + M) - str_set.size();

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

        // INIT 
        str_set.clear();
	}
	return 0;
}