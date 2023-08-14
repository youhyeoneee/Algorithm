#include <stdio.h>
int N, K, a, b;
bool c[1000001];
int prime[1000001];
int main() {
    int cnt = 0;
    for (int i = 2; i < 1000001; i++) {
        c[i] = true;
    }
    for (int i = 2; i < 1000001; i++) {
        if (c[i]) {
            prime[cnt++] = i;
            for (long long j = (long long)i*i; j < 1000001; j += i) {
                c[j] = false;
            }
        }
    }
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        int a = 0, b = 0;
        for (int i = 0; i < cnt; i++) {
            if (prime[i] > N) break;
            if (c[N - prime[i]]) {
                a = prime[i];
                b = N - prime[i];
                break;
            }
        }
        if (a == 0) {
            printf("Goldbach's conjecture is wrong.\n");
        }
        else {
            printf("%d = %d + %d\n", N, a, b);
        }

    }
    return 0;
}