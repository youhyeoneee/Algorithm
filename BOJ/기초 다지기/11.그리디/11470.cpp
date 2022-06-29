#include <iostream>
#include <vector>

// 브론즈3
using namespace std;

int main(){
    int N, temp, now = 0, result = 0;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> temp;

        if (temp == now){
            result++;
            now = (now+1)%3;
        }
    }

    cout << result << '\n';

    return 0;
}