#include <iostream>

using namespace std;

// https://sexycoder.tistory.com/94

long long gcd(long long a, long long b){
    while(b > 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long result = gcd(A, B);

    for (long long i=0; i<result; i++)
        cout << 1;
    cout << '\n';
    
    return 0;
}