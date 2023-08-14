#include <iostream>

using namespace std;

int gcd(int a, int b){
    while(b > 0){
        int temp = b;
        b = a%b;
        a = temp;
    }

    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;

    cin >> A >> B;

    cout << gcd(A, B) << '\n';
    cout << lcm(A, B) << '\n';
    return 0;
}