#include <iostream>

using namespace std;

int main(){

    int T, N;
    long long p[101] = {0, };  
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    cin >> T;

    for (int i=0; i<T; i++){
        cin >> N;


        for(int j=5; j<=N; j++)
            p[j] = p[j-1] + p[j-5];

        cout << p[N] << endl;

    }


    return 0;
}