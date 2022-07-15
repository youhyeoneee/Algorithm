#include <stdio.h>
int N,K;
bool is_prime[1001];

int main() 
{
    scanf("%d%d",&N,&K);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=N;i++) is_prime[i] = true;

    int ans = -1;
    for (int i = 2; i <= N; i++) {
        if(!is_prime[i]) continue;

        for (int j = i; j <= N; j+=i) {
            if(!is_prime[j]) continue;
            is_prime[j] = false;
            if(--K == 0) ans = j;
        }
        if(K==0) break;
    }
    printf("%d",ans);
}