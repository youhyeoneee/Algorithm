#include<stdio.h>

struct H {
    unsigned long long a, b, c, d;
};
H mul(H A, H B) {
    return {
        (A.a*B.a + A.b*B.c) % 1000000,
        (A.a*B.b + A.b*B.d) % 1000000,
        (A.c*B.a + A.d*B.c) % 1000000,
        (A.c*B.b + A.d*B.d) % 1000000
    };
}
unsigned long long N;
int main() {

    scanf("%lld", &N);
    H cal = {1,1,1,0};
    H r = { 1,0,0,1 };
    for (; N > 0; N  = N >> 1) {
        if (N & 1) {
            // 곱하기 
            r = mul(r, cal);
        }
        cal = mul(cal, cal);
    }
    printf("%lld", r.b);

    return 0;
}