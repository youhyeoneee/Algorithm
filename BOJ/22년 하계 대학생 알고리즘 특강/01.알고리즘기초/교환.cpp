#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, M;

/*
1000000 10
*/
int swap(int num, int a, int b) {
    int aa = pow(10, a);
    int bb = pow(10, b);
    int an = ((num / aa) % 10);
    int bn = ((num / bb) % 10);

    if (an == 0 && b == M-1) return -1;

    return num - (an*aa + bn*bb) + (an*bb + bn*aa);
}

int main() {

    scanf("%d %d", &N, &K);
    // 6자리 중에 두개를 고름 > 15  
    // 최대 10번 
    int n = N;
    for (M = 1; M < 7; M++) {
        n /= 10;
        if (n == 0) break;
    }

    priority_queue<int, vector<int>, less<int>> q[2]; // ={ priority_queue<int, vector<int>, less<int>>(), priority_queue<int, vector<int>, less<int>>()};
    int t = 0, nt = 1;

    q[t].push(N);
    int prev = -1;
    for (int k = 0; k < K; k++) {
        prev = -1;
        while (!q[t].empty()) {

            int num = q[t].top(); 
            q[t].pop();
            if (num == prev) continue;
            prev = num;

            int next;
            for (int a = 0; a < M; a++) {
                for (int b = a + 1; b < M; b++) {
                    next = swap(num, a, b);
                    if(next != -1) q[nt].push(next);
                }
            }
        }
        t = nt; 
        nt = (nt + 1) & 1;
    }
    if (q[t].empty()) printf("-1\n");
    else {
        int result = q[t].top();
        printf("%d\n", result);
    }

    return 0;

}