#include <iostream>

// 분수의 합

using namespace std;


int gcd(int a, int b){
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int main(){

    int A, B, a, b; // A/B a/b 

    cin >> A >> B;
    cin >> a >> b;

    int resultA, resultB;

    resultA = A*b + a*B;
    resultB = B*b;

    // 분자와 분모의 최대공약수 구하기 
    int GCD = gcd(resultB, resultA);

    cout << resultA/GCD << ' ' << resultB/GCD;


    return 0;
}