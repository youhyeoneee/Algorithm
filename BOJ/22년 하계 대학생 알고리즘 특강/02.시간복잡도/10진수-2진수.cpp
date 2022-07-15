#include <stdio.h>
#include <algorithm>
#include <queue>

// 10진수 > 2진수로 바꾸는 코드 예시
using namespace std;

int main() {

    int a = 26; // 11010 = 2 + 8 + 16 = 26 
    int cal = 1;
    char str[6];
    int si = 0;

    // 26  = 1 1 0 1 0   
    for (int i = a; i > 0; i = i >> 1) {
        if ((i & 1)) {
            str[si] = '1';
        }
        else {
            str[si] = '0';
        }
        si++;
    }
    for (int i = a; i > 0; i = i >> 1) {
        printf("%c", str[--si]);
    }
    return 0;
}