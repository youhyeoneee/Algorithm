#include <iostream>

using namespace std;

int main(){

    long long int h, b, c, s;
    //1초 동안 마이크로 소리강약을 체크하는 수를 h
    //한 번 체크한 결과를 저장하는 비트 b
    //좌우 등 소리를 저장할 트랙 개수인 채널 c
    //녹음할 시간 s

    cin >> h >> b >> c >> s;
    
    printf("%.1lf MB", ((double)(h*b*c*s)/(double)(1024*1024*8)));
    return 0;
}