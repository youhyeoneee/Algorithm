#include <iostream>
#include <string>

using namespace std;

string A, B;

int main()
{   
    cin >> A;
    cin >> B;

    if (A.length() >= B.length()) cout << "go";
    else cout << "no";

    return 0;
}