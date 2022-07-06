#include <iostream>

// 최소 힙

using namespace std;

int heap[1024 * 128 * 2];
int N, x, ti; // 삽입될 인덱스

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;


    ti = 1;

    for(int i=0; i<N; i++){
        cin >> x;

        // x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산
        if (x>0){
            // 1. 트리의 가장 마지막 위치에 노드를 삽입한다.
            heap[ti++] = x;

            int idx = ti-1, parent = idx>>1;

            while(idx > 1 && heap[idx] < heap[parent]){             // 2. 추가된 노드와 그 부모 노드가 힙 조건을 만족하는지 확인한다.
                // 3. 만족하지 않는다면 부모와 자식의 키 값을 바꾼다.
                swap(heap[idx], heap[parent]);
                idx = parent;
                parent = (idx>>1);
                // 4. 조건에 만족하거나 추가된 노드가 루트에 도달할 때까지 2~3을 반복한다.
            }
            
        }
        
        // x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우
        else if (x==0) {

            // 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
            if (ti == 1) cout << 0 << '\n';

            else{
                // 1. 힙의 삭제 연산은 항상 루트 노드를 삭제한다.
                cout << heap[1] << '\n';

                // 트리의 가장 마지막 노드를 루트 자리로 삽입한다.
                heap[1] = heap[--ti];
                int i = 1, left = i*2, right = i*2 + 1;
                // 바꾼 위치의 노드가 힙 조건을 만족하는지 확인한다.
                // 조건을 만족하거나 리프 노드에 도달할 때 까지 3~4를 반복한다.
                while(i*2+1 <ti){
                    left = i*2;
                    right = i*2 + 1;
                    // 만족하지 않는다면 왼쪽 자식과 오른쪽 자식 중 적합한 노드와 키 값을 바꾼다.
                    if (heap[left] < heap[right]){
                        if(heap[i] <= heap[left]) break;
                        swap(heap[i], heap[left]);
                        i = left;
                    }
                    else{
                        if (heap[i] <= heap[right]) break;
                        swap(heap[i], heap[right]);
                        i = right;
                    }
                }

                left = i*2;
                if (left < ti && heap[i] > heap[left])
                    swap(heap[i], heap[left]);

            }
        }
    }

    return 0;
}