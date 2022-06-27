#include <iostream>

using namespace std;

int main(){

    int A, B;

    int b1 = (B%100);
    int b2 = B%(100*b1);
    int b3 = B%(b1*100 + b2*10);

    cin >> A;
    cin >> B;

    cout << b1 << '\n';
    cout << b2 << '\n';
    cout << b3 << '\n';

    cout << A * b3 << '\n';
    cout << A * b2 << '\n';
    cout << A * b1 << '\n';
    cout << A * B << '\n';



    return 0;
}