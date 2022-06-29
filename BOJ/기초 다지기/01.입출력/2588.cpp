#include <iostream>

using namespace std;

int main(){

    int A, B;


    cin >> A;
    cin >> B;

    int b3 = B%10;
    int b2 = (B%100)-b3;
    int b1 = B-(b2+b3);
    
    cout << A * b3 << '\n';
    cout << A * b2 / 10 << '\n';
    cout << A * b1 / 100 << '\n';
    cout << A * B << '\n';



    return 0;
}