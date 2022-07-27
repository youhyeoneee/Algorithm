#include <stdio.h>

int N, M, K;

long long int tree[1024*1024*2];
int tmpN;

void update(int i,long a) {
    i = tmpN + i - 1;
    tree[i] = a;
    i = i >> 1;
    while (i > 0) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
        i = i >> 1;
    }
}
long long sum(int a, int b) {
    a = tmpN + a - 1;
    b = tmpN + b - 1;
    long long int sum = 0;
    while (a <= b) {
        if ((a & 1) == 1) // 오른쪽 child 
            sum += tree[a];
        if ((b & 1) == 0) //왼쪽 child
            sum += tree[b];
        a = (a + 1) >> 1;
        b = (b - 1) >> 1;
    }
    return sum;
}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (tmpN = 1; tmpN < N; tmpN = tmpN << 1); // N 보다 크거나 같은 2의 제곱수 

    for (int i = 0; i < tmpN * 2; i++) tree[i] = 0;
    for (int i = tmpN; i < tmpN + N; i++) { // leaf 채우기 
        scanf("%lld", &tree[i]);
    }
    for (int i = tmpN - 1; i >= 1; i--) { // internal 채우기 
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    long long int a, b, c;
    for (int q = 0; q < M + K; q++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            // a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고 
            update(b, c);
        }
        else {
            // a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.
            printf("%lld\n", sum(b, c));
        }
    }

    return 0;
}
