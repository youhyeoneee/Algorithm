#include <stdio.h>

int N, M;
int A[10000];
int main() {

    scanf("%d %d", &N, &M);
    int sum = 0, n = 0;
    int si = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
        while (sum > M) {
            sum -= A[si];
            si++;
        }
        if (sum == M) n++;

    }

    printf("%d", n);

}