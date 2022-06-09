#include <iostream>

using namespace std;

int main(){

    int N, K, cnt = 0;

    cin >> N >> K;

    while(N!=1){
        // 나누기 되면 나누기
        if(N%K==0)
            N/= K;
        else //안되면 빼기
            N--;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;

}