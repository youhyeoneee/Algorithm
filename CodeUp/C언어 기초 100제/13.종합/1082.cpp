#include <iostream>

using namespace std;

int main(){

    int a;

    scanf("%X", &a);

    for (int i=1; i<16; i++){
        printf("%X*%X=%X\n", a, i, a*i);
    }
    return 0;
}