#include <iostream>
#include <algorithm>
#define MAX 100001

// 나중에 다시 풀게요

using namespace std;

int test_case;
int T, N, M;

int A[3001], B[101];

long long result = 0;
long long visited = 0; 
int length = 0; // visited 길이

int dp[3101][101]; // dp[k][visited];

void print_B(){
    cout << ">> B \n";
    for(int i=0; i<M; i++){
        cout << B[i] << " ";
    }
    cout << "\n";

}

int getAbit(unsigned short x, int n) { // getbit()
  return (x & (1 << n)) >> n;
}


int findMaxInA(){
    int max = 0;
    int idx = 0;
    for(int i=length; i>=1; i--){
        // MAX 비교 
        if (getAbit(visited, i) == 0) {
            if (max < A[i]) {
                max = A[i];
                idx = i;
            }
        }
    }

    return idx;
}


void isPossible(int a_idx, int b_idx){
    if (getAbit(visited, a_idx+1)){
         
    }
    if (getAbit(visited, a_idx-1))

}

int main(int argc, char** argv)
{


	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   

        // INPUT
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> A[i];
        
        cin >> M;

        for(int i=0; i<M; i++)
            cin >> B[i];

        // INIT
        length = N; // 길이 저장
        int b_start = 0;
        int b_end = M-1;
        
        sort(B, B+M, greater<int>()); // B 내름차순 정렬
        // PROCESS

        print_B();


        for(int i=1; i<=N+M; i++){
            int max_a_idx = findMaxInA();
            int max_a = A[max_a_idx];
            int max_b = B[b_start];
            cout << visited << '\n';

            // A 가 크면
            if (max_a > max_b){
                visited |= (1 << max_a_idx); // 방문 표시
                // 붙어있을 경우
                if (isPossible(max_a_idx))

                dp[i][visited] = result + A[max_a_idx][visited];
            }
            // B가 있는 게 크면
            else { 

            }

            cout << visited << '\n';

        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";

	}
	return 0;
}