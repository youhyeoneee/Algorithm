#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
int N;

int tree[1024 * 128 * 2]; // root 1
int ti;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    scanf("%d", &N);

    ti = 1; // heap 데이터가 들어가야 할 인덱스

    for(int n=0; n<N; n++){
        int x;
        scanf("%d", &x);

        if (x==0){
            // heap에서 가장 작은 값 출력
            if (ti==1) printf("0\n");
            else{
                printf("%d\n", tree[1]);
                tree[1] = tree[--ti];
                int i= 1, left_child = i*2, right_child = i*2+1;

                while(i*2+1 <ti){
                    left_child = i*2;
                    right_child = i*2+1;

                    if (tree[i]<=tree[left_child] && tree[i] <= tree[right_child]) break;
                    else if (tree[left_child] < tree[right_child]){
                        swap(tree[i], tree[left_child]);
                        i = left_child;
                    }
                    else{
                        swap(tree[i], tree[right_child]);
                        i = right_child;
                    }
                }

                left_child = i*2;
                if (left_child < ti && tree[left_child] < tree[i])
                        swap(tree[i], tree[left_child]);
            }
        }
        else{
        // x를 heap에 추가

            tree[ti++] = x;
            int i=ti-1, pi = i>>1; // 나누기 2 한 것과 동일

            while(i>1 && tree[i] < tree[pi]){
                swap(tree[i], tree[pi]);
                i = pi;
                pi = (i>>1);
            }
        }   
    }
    

    return 0;
}
