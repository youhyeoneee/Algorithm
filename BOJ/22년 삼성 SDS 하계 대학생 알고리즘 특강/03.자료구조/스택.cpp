#include <stdio.h>
#include <string.h> 

int N;

int stack[10000]; 
int si = 0, n = 0;
char s[30];
int main() {
    scanf("%d", &N);
    int si = 0;

    for (int i = 0; i < N; i++) {

        scanf("%s", s);
        if (strcmp(s, "pop") == 0) {
            if (si == 0) printf("-1\n");
            else printf("%d\n", stack[--si]);
        }
        else if (strcmp(s, "size") == 0) {
            printf("%d\n", si);
        }
        else if (strcmp(s, "empty") == 0) {
            if (si == 0) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(s, "top") == 0) {
            if (si == 0) printf("-1\n");
            else printf("%d\n", stack[si-1]);
        }
        else {
            scanf("%d", &n);
            stack[si++] = n;
        }
    }

    return 0;
}