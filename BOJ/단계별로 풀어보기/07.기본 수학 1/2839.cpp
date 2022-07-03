#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int cnt = N/5;

    if (cnt == 0){
        if (N%3 == 0) cout << N/3;
        else cout << -1;
    }
    else{
        do{
            if ((N-(cnt*5))%3 == 0) {cout << cnt + (N-(cnt*5))/3; return 0;} // 여기서 끝내야 한다!
            else cnt--;
        }while(cnt > 0);

        if (N%3 == 0) cout << N/3;
        else if (cnt <= 0) cout << -1;
    }

    return 0;
}