#include <iostream>


using namespace std;

int balloons[1000];
int N;

int moveIdx(int idx, int num) {
    int cnt = 0;
    int dir = 1; // 오른쪽
    if (num < 0) dir = -1; // 왼쪽 

    while(cnt < abs(num)) {

        idx = (idx + dir) % N;   
        if (idx < 0) idx = N-1;    

        if (balloons[idx] != 0) cnt++;

    }


    return idx;
}


int main() {

    cin >> N;

    int num;
    for(int i=0; i<N; i++) {
        cin >> num;
        balloons[i] = num;
    }

    int idx = 0;

    for(int i=0; i<N-1; i++) {
        cout << idx + 1 << " ";
        int num = balloons[idx];    
        balloons[idx] = 0;
        idx = moveIdx(idx, num);
    }

    cout << idx + 1 << " ";


    return 0;
}