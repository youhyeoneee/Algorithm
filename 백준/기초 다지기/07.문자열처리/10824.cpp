#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B,C,D;

    cin >> A >> B >> C >> D;
    long long result;

    string AB, CD;
    AB = to_string(A) + to_string(B);
    CD = to_string(C) + to_string(D);

    result = stoll(AB) + stoll(CD);
    
    cout << result << '\n';

    return 0;
}