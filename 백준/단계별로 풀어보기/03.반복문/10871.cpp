#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, N, X;

    cin >> N >> X;
    for (int i=0; i<N; i++){
        cin >> A;
        if (A<X) cout << A << ' ';
    }

    return 0;
}