#include <stdio.h>
#include <string.h>
#include <stdlib.h>   

#define MAX 1000000000

using namespace std;

long long stack[1001];
int si = 0;
char command[100000][20];
int ci; 

void print();
void run_program();
bool is_error;

int main() {

    bool run = true;
    int t = 0;
    while (true) {
        if(t!= 0) printf("\n");

        ci = 0;
        for (; ci < 100000; ci++) {
            scanf("%s", command[ci]);
            if (strcmp(command[ci], "NUM") == 0) {
                scanf("%s", command[ci]);
            }
            if (strcmp(command[ci], "END") == 0) break;
            if (strcmp(command[ci], "QUIT") == 0) {
                run = false;
                break;
            }
        }

        if (!run) break; 

        int N = 0, first = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            si = 0;
            scanf("%d", &first);
            stack[si++] = first;
            run_program();
            print();
        }
        t++;
    }

}

void print() {
    if (si != 1 || is_error) printf("ERROR\n");
    else printf("%d\n", stack[si - 1]);
}
void run_program() {

    // program error 정의  
    // 1. 숫자가 부족해서 연산을 수행할 수 없을 때
    // 2. 0으로 나눴을 때 (DIV, MOD)
    // 3. 연산 결과의 절댓값이 10^9 를 넘어갈 때
    is_error = false;

    for (int i = 0; i < ci; i++) {

        if (strcmp(command[i], "DUP") == 0) {
            if (si == 0) {
                is_error = true;
                break;
            }
            stack[si] = stack[si - 1];
            si++;
        }
        else if (strcmp(command[i], "POP") == 0) {
            if (si == 0) {
                is_error = true;
                break;
            }
            si--;
        }       
        else if (strcmp(command[i], "INV") == 0) {
            if (si == 0) {
                is_error = true;
                break;
            }
            stack[si - 1] = -stack[si - 1];
        }
        else if (strcmp(command[i], "SWP") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            int tmp = stack[si - 1];
            stack[si - 1] = stack[si - 2];
            stack[si - 2] = tmp;
        }
        else if (strcmp(command[i], "ADD") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            stack[si-2] += stack[si - 1];
            si--;
            if (stack[si - 1] > MAX || stack[si-1] < -MAX) {
                is_error = true;
                break;
            }
        }
        else if (strcmp(command[i], "SUB") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            stack[si - 2] -= stack[si - 1];
            si--;
            if (stack[si - 1] > MAX || stack[si - 1] < -MAX) {
                is_error = true;
                break;
            }
        }
        else if (strcmp(command[i], "MUL") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            stack[si - 2] *= stack[si - 1];
            si--;
            if (stack[si - 1] > MAX || stack[si - 1] < -MAX) {
                is_error = true;
                break;
            }
        }
        else if (strcmp(command[i], "DIV") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            if (stack[si - 1] == 0) {
                is_error = true;
                break;
            }
            stack[si - 2] = stack[si - 2] / stack[si - 1];
            si--;
        }
        else if (strcmp(command[i], "MOD") == 0) {
            if (si < 2) {
                is_error = true;
                break;
            }
            if (stack[si - 1] == 0) {
                is_error = true;
                break;
            }
            stack[si - 2] = stack[si - 2] % stack[si - 1];
            si--;
        }
        else {
            stack[si++] = atoi(command[i]);
        }

    }

}