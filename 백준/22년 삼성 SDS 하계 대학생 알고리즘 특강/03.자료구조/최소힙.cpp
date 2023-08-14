#include <stdio.h>
#include <queue>

using namespace std;
int N;

int tree[1024 * 128 * 2]; // root 1, 
int ti;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {

    scanf("%d", &N);

    ti = 1;

    for (int n = 0; n < N; n++) {

        int x;
        scanf("%d", &x);
        if (x == 0) {
            // heap에서 가장 작은값 출력
            if (ti == 1) printf("0\n");
            else {
                printf("%d\n", tree[1]);
                tree[1] = tree[--ti];
                int i = 1, left_child = i * 2, right_child = i + 2 + 1;
                while (i * 2 + 1 < ti) {
                    left_child = i * 2;
                    right_child = i * 2 + 1;
                    if (tree[left_child] < tree[right_child]) {
                        if (tree[i] <= tree[left_child]) break;
                        swap(tree[i], tree[left_child]);
                        i = left_child;
                    }
                    else {
                        if (tree[i] <= tree[right_child]) break;
                        swap(tree[i], tree[right_child]);
                        i = right_child;
                    }
                }
                left_child = i * 2;
                if (left_child < ti && tree[i] > tree[left_child]) {
                    swap(tree[i], tree[left_child]);
                }
            }

        }
        else {
            // x를 heap에 추가 
            tree[ti++] = x;

            int i = ti - 1, ni = i >> 1;
            while (i > 1 && tree[i] < tree[ni]) {
                swap(tree[i], tree[ni]);
                i = ni;
                ni = (i >> 1);
            }

        }
    }

    return 0;

}