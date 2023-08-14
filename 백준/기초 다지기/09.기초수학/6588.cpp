#include <iostream>
#include <stdio.h>
#include <cmath>
#define SIZE 1000001

using namespace std;

// 에라토스테네스의 체 초기화 
bool arr[SIZE] = {false};

int main(){ 

    int n = -1;
    arr[0] = true;
    arr[1] = true;


    // 소수 판별
    for(int i=2; i<=sqrt(SIZE); i++){
        if (arr[i] == true)
            continue;
        for(int j=i+i; j<=SIZE; j+=i){
            if(arr[j] == false)
                arr[j] = true;
        }
    }

    while(true){
        scanf("%d", &n);

        if (n == 0)
            return 0;
        else{
            bool find = false;
            int I;
            for(int i=2; i<=n/2; i++){
                if (!arr[i] && !arr[n-i]){
                    I = i;
                    find = true;
                    break;
                }
            }               
            if (find)
                printf("%d = %d + %d\n", n, I, n-I);
            else
                printf("Goldbach's conjecture is wrong.");
        }
    }
    return 0;
}