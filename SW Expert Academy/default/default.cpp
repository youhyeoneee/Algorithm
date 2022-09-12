#include <iostream>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int result;

void Init(){
    result = 0;
}

void Input(){
   
}

void Solve(){
   
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