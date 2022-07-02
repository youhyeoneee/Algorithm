#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    string A, B;

    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    if (stoi(A) > stoi(B)) cout << A;
    else cout << B;

    return 0;
}