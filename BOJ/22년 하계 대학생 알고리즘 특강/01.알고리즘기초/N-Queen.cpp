#include<stdio.h>

int N;
int result; 
int c[15];

void put_queen(int i) { // i 번째 줄에 자리 찾아 넣기  

    if (i == N) {
        result++;
        return;
    }

    int gap;
    int d[15];
    for (int j = 0; j < N; j++) {
        d[j] = -1;
    }

    for (int j = 0; j < N; j++) {
        if (c[j] != -1) {
            gap = i - c[j];
            if (j + gap < N)  d[j + gap] = c[j];
            if (j - gap >= 0) d[j - gap] = c[j];
        }
    }
    for (int j = 0; j < N; j++) {
        if (c[j] == -1 && d[j] == -1) {
            c[j] = i;
            put_queen(i + 1);
            c[j] = -1;
        }
    }
}
int main() {

    result = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) c[i] = -1;

    put_queen(0);

    printf("%d", result);

    return 0;
}