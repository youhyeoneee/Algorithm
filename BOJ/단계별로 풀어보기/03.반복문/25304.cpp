#include <iostream>

using namespace std;

int main() {
    long long X, sum = 0;
    int N, a, b;

    cin >> X;

    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> a >> b;

        sum += (a * b);
    }

    if (sum == X) cout << "Yes";
    else cout << "No";
}