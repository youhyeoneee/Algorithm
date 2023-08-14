#include <iostream>

using namespace std;


const int SIZE = (1<<16); // DP 테이블 사이즈 설정을 위한 상수
int ALLVISITED; // 

inline int mymin(int a, int b) {return (a < b)? a:b;}
int N; // 도시의 수 N
int W[16][16]; // W[i][j]는 도시 i에서 j로 가기 위한 비용
int D[16][SIZE]; // [i][j] 현재 상태에서의 최소비용 (j를 방문하고 i에 도착했을 때)

int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> W[i][j];
            if (!W[i][j]) W[i][j] = 2000000; // 0으로 주어진 값은 무한대로 바꿈
        }
    }

    ALLVISITED = (1 << N) - 1; // 2진수로 111....111(N개)인 수를 만드는 것

    // 출발지점과 도착지점을 0으로 고정 (한바퀴 도는 것이므로 상관 없음)
    
    // 현재 D[i][j] 상태일 경우
    // 다음으로 진행할 경우를 가정하자.

    for(int i=0; i<N; i++){
        for(int j=1; j<=ALLVISITED; j++){
            if (j & (1<<i)) { // j라는 방문 정보에 i를 방문한 적이 있어야 함
                for(int k=0; k<N; k++){
                    // j라는 방문 정보에서 k를 방문한 적이 있는지 검사
                    if (j & (1<<k)) continue;  // 만약에 k가 이미 방문한 경우라면 skip
                    
                    // j의 상태가 이미 k를 방문한 상태가 아닐 때만 아래 구문을 수행한다.
                    if(D[k][j | (1<<k)] == 0) D[k][j | (1<<k)] = D[i][j] + W[i][k]; 
                    else D[k][j | (1<<k)] = mymin(D[k][j |(1<<k)], D[i][j] + W[i][k]);         
                }
            }
        }
        
    }
    

    int Answer;
    // Answer = 최소(D[1][ALLVISITED] + W[1][0], D[1][ALLVISITED] + W[2][0], ..., D[N-1][ALLVISITED] + W[N-1][0]);
    cout << Answer;

    
    return 0;
}