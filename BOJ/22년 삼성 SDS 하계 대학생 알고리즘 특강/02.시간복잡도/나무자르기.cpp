#include <stdio.h>

int N, MAX = 0;
long long M, h[1000000];

long long cut(int k) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] > k) sum += h[i]- k;
    }
    return sum;
}
int binary_search(int s, int e) {
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e) {
        mid = (s + e) / 2;
        if (cut(mid) < M) { // 더 밑으로
            e = mid - 1;
        }
        else { //  더 위로
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main() {

    scanf("%d %d", &N, &M);
    MAX = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
        MAX = MAX < h[i] ? h[i] : MAX;
    }

    printf("%d", binary_search(0, MAX));

    return 0;
}