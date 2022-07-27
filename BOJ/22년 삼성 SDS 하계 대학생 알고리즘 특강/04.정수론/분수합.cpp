#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main() 
{
    int A1,B1,A2,B2;
    scanf("%d %d",&A1,&B1);
    scanf("%d %d",&A2,&B2);
    int U,D,g;
    D = B1*B2; // 분모 통분 
    U = A1*B2 + A2*B1; // 분자 계산 
    g = gcd(D,U);
    printf("%d %d",U/g,D/g);
}