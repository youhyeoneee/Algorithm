#include <iostream>

using namespace std;

int main(){

    int T, H, W, N, Y, X;

    cin >> T;

    for(int i=0; i<T; i++){

        cin >> H >> W >> N;

        Y = N%H;
        X = N/H;

        if (Y == 0) Y = H; // 맨 꼭대기 층
        else X++;

    
        printf("%d%02d\n", Y, X);
    }
    return 0;
}