#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int a, b;
    
    cin >> a >> b;

    if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2))
        cout << "A";
    else 
        cout << "B";
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}