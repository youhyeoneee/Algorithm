#include <stdio.h>
#include <string.h> 

int N;

int q[10000];
int s = 0, e= 0, n = 0;
char str[30];
int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%s", str);
        if (strcmp(str, "pop") == 0) {
            if (s == e) printf("-1\n");
            else printf("%d\n", q[s++]);
        }
        else if (strcmp(str, "size") == 0) {
            printf("%d\n", e-s);
        }
        else if (strcmp(str, "empty") == 0) {
            if (s==e) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(str, "front") == 0) {
            if (s == e) printf("-1\n");
            else printf("%d\n", q[s]);
        }
        else if (strcmp(str, "back") == 0) {
            if (s==e) printf("-1\n");
            else printf("%d\n", q[e - 1]);
        }
        else {
            scanf("%d", &n);
            q[e++] = n;
        }
    }

    return 0;
}