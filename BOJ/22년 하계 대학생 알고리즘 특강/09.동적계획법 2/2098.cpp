#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

const int SIZE = (1<<16); // DP 테이블 사이즈 설정을 위한 상수

int N; // 도시의 수 N
int W[16][16]; // W[i][j]는 도시 i에서 j로 가기 위한 비용
int D[16][SIZE]; // [i][j] 현재 상태에서의 최소비용 (j를 방문하고 i에 도착했을 때)
int v = 0;

int main(){

    cout << SIZE;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> W[i][j];
            if (!W[i][j]) W[i][j] = 2000000; // 0으로 주어진 값은 무한대로 바꿈
        }
    }

    // 초기화 
    for(int i=0; i<N;){
        D[0][i] = W[0][i];
    }



    
    return 0;
}