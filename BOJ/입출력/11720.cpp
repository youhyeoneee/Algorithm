#include <stdio.h>

using namespace std;

int main(){
    int N;
    int sum = 0;
    scanf("%d", &N);
    char text[N];
    scanf("%s", text);
    
    for (int i=0; i<N; i++){
        sum += text[i] - '0';
    }

    printf("%d", sum);

    return 0;
}