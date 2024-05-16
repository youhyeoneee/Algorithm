#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int N;
    int answer = 0;
    cin >> N;
    
    while(N>0) {
        answer += N % 10;
        N /= 10;
    }

	cout << answer;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}