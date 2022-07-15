#include <stdio.h>

long long gcd(long a, long b) {
    if (b == 0)  return a;

    return gcd(b, a%b);
}

int t;
int main() {

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long long K, C;
        scanf("%d %d", &K, &C);

        if (gcd(K, C) != 1) {
            printf("IMPOSSIBLE\n");
        }
        else {
            long long s1 = 1, t1 = 0, r1 = K;
            long long s2 = 0, t2 = 1, r2 = C;

            while (r2 > 1) {
                long q = r1 / r2;
                long temp = 0;
                temp = s2;
                s2 = s1 - q * s2;
                s1 = temp;

                temp = t2;
                t2 = t1 - q * t2;
                t1 = temp;
                temp = r2;
                r2 = r1 - q * r2;
                r1 = temp;
            }

            while (s2 >= 0 || t2 <= 0) {
                s2 = s2 - C;
                t2 = t2 + K;
            }
            if (t2 > 1000000000L) {
                printf("IMPOSSIBLE\n");
            }
            else {
                printf("%d\n", t2);
            }
        }

    }

}