#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
struct Player {
    int i;
    int power;
};
Player p[500000];

int tree[1024 * 1024];
int tmpN = 1024 * 512;

bool comp_power(const Player &a, const Player &b) {
    if (a.power < b.power) return true;
    return false;
}
bool comp_i(const Player &a, const Player &b) {
    if (a.i < b.i) return true;
    return false;
}
int get_sum(int a, int b) {
    int sum = 0;
    a = tmpN + a - 1;
    b = tmpN + b - 1;
    while (a <= b) {
        if ((a & 1) == 1) sum += tree[a];
        if ((b & 1) == 0) sum += tree[b];
        a = (a + 1) >> 1;
        b = (b - 1) >> 1;
    }
    return sum;
}

void update(int a) {
    a = tmpN + a - 1;
    while (a > 0) {
        tree[a] += 1;
        a = a >> 1;
    }
}
int main() {
    scanf("%d", &N);
    int power = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &power);
        p[i] = { i, power };
    }
    sort(p, p + N, comp_power);

    int pi = 0, prev_power = 0; 
    for (int i = 0; i < N; i++) {
        if (prev_power != p[i].power) pi++;
        p[i].power = pi;
    }

    sort(p, p + N, comp_i);

    for (int i = 0; i < tmpN * 2; i++) tree[i] = 0;

    for (int i = 0; i < N; i++) {
        printf("%d\n", i + 1 - get_sum(1, p[i].power));
        update(p[i].power);
    }

}