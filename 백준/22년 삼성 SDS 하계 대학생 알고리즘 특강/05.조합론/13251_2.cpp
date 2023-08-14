#include <iostream>

using namespace std;

int M, K;
int s[50];

int main(){

    scanf("%d", &M);
    int sum = 0; // 조약돌 전체 개수 N
    for(int i=0; i<M; i++){
        scanf("%d", &s[i]);
        sum += s[i];
    }

    scanf("%d", &K);

    double a=0, b=0, tmp=0;

    for(int i=0; i<M; i++){
        tmp = 1.0;
        for(int j=0; j<K; j++)  
            tmp *= s[i] - j;
        a += tmp;
    }

    b = 1.0;
    for(int j=0; j<K; j++)
        b *= sum-j;

    printf("%.15lf", (a/b));

    return 0;
}