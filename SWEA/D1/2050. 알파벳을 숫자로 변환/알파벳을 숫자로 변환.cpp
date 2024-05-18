#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    string str;
    cin >> str;
    
   	for(char ch : str) {
        if (ch >= 'A' && ch <= 'Z') 
	        cout << (int)(ch - 'A' + 1) << " ";
        else if (ch >= 'a' && ch <= 'z')
            cout <<  (int)(ch - 'a' + 1) << " ";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}