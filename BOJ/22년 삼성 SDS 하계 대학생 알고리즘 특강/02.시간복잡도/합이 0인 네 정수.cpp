#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int A[4000];
int B[4000];
int C[4000];
int D[4000];
int AB[16000000];
int CD[16000000];
int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        scanf("%d", &B[i]);
        scanf("%d", &C[i]);
        scanf("%d", &D[i]);
    }
    int ii = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[ii] = A[i] + B[j];
            CD[ii] = C[i] + D[j];
            ii++;
        }
    }

    sort(AB, AB + ii);
    sort(CD, CD + ii);

    int abi = 0, cdi = ii - 1;

    long long ans = 0;
    int an, bn = 0;

    while (abi < ii && cdi >= 0) {
        if (AB[abi] + CD[cdi] == 0) {
            an = bn = 0;
            while (abi+an < ii && AB[abi] == AB[abi + an]) an++;
            while (cdi-bn >= 0 && CD[cdi] == CD[cdi - bn]) bn++;
            ans += (long long) an * bn;
            abi += an;
            cdi -= bn;

        }else if (AB[abi] + CD[cdi] < 0) abi++;
        else cdi--;
    }

    printf("%lld\n", ans);

    return 0;
}