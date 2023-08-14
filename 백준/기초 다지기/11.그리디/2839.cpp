#include <iostream>

using namespace std;

int main(){
    int N, cnt = -1;

    cin >> N;

    for(int i = 0; i * 3 <= N; i++){
        if ((N - (i*3)) % 5 == 0){
            cnt = i + ((N - (i*3)) / 5);
            break;
        }
    }

    cout << cnt << '\n';
    return 0;
}