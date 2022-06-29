#include <iostream>

using namespace std;

int gcd(int a, int b){
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, T;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> A >> B;
        cout << lcm(A, B) << '\n';
    }

    return 0;
}