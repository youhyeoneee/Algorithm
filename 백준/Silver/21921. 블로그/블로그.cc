#include <iostream>
#include <vector>

#define MAX 250000
using namespace std;

int N, X;
int visitCnt[MAX+4];
int maxVisit;

int main() {

    cin >> N >> X;

    for(int i=0; i<N; i++) {
        cin >> visitCnt[i];
    }


    int sum = 0; 

    int startIdx = 0;
    int endIdx = startIdx + X;
    // 0 ~ N-X 값 더해주기 
    for(int i=startIdx; i<endIdx; i++) {
        sum += visitCnt[i];
    }

    // 초기화
    int maxSum = sum;
    int cnt = 1;

    // 앞으로 이동하면서, sum - 맨앞요소 && sum + 그 다음요소 해주기 
     for(endIdx; endIdx<N; endIdx++) {
        sum -= visitCnt[startIdx]; 
        sum += visitCnt[endIdx];
        

        startIdx++;

        // max보다 크면 
        if (maxSum < sum) {
            maxSum = sum;  
            cnt = 1;
        } else if (maxSum == sum) {  // max와 같으면 
            cnt++;
        }
    }

    if (maxSum == 0) {
        cout << "SAD";
    } else {
        cout << maxSum << '\n' << cnt << '\n';
    }

    return 0;
}