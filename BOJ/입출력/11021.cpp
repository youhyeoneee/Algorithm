#include <stdio.h>

using namespace std;

int main(){
    int A, B, T;
    scanf("%d", &T);

    for(int i=1; i<=T; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
    }
   
    return 0;
}