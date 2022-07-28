#include <iostream>
#define MAX_NODE 10000

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

// 새 노드 생성
Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

// 초기화
void init()
{
    head = getNode(-1);
    head->next = nullptr;
    head->prev = nullptr;
    

}

// 맨 뒤에 노드 추가
void addNode2Tail(int data)  // 2
{
    Node* node = getNode(data);
    Node* ptr = head;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    node->next = ptr->next;
    ptr->next = node;
    node->prev = ptr;

}


// 지정된 순서(num)에 노드 추가 (1-2-3-4-5-...)
void addNode2Num(int data, int num)  // 3
{
    Node* node = getNode(data);
    Node* ptr = head;

    for(int i=0; i<num; i++){
        ptr = ptr->next;
        if(ptr->next == nullptr) break;
    }
    
    node->next = ptr->next;
    if (ptr->next != nullptr) ptr->next->prev = node;
    ptr->next = node;
    node->prev = ptr;

}


// 지정된 순서(num)에 노드 삭제 (1-2-3-4-5-...)
void deleteNode2Num(int num)  // 3
{
    Node* prev_ptr = head;

    for(int i=0; i<num; i++){
        prev_ptr = prev_ptr->next;
        if(prev_ptr->next == nullptr) break;
    }
    
    if (prev_ptr->next != nullptr){
        Node* curr_ptr = prev_ptr->next;
        prev_ptr->next = curr_ptr->next;
        if (curr_ptr->next != nullptr)
            curr_ptr->next->prev = prev_ptr;
    }
}

// 지정된 순서(num)에 노드 data 바꾸기
void changeNode2Num(int data, int num)  // 3
{
    Node* ptr = head;

    for(int i=0; i<=num; i++){
        ptr = ptr->next;
        if(ptr->next == nullptr) break;
    }
    
    if(ptr != nullptr) ptr->data = data;
}


// 노드의 data 정보를 차례대로 output[]에 저장하고 노드 개수를 리턴
int getList(int output[MAX_NODE])  // 6
{
    Node* ptr = head;
    int cnt = 0;
    while(ptr->next != nullptr){
        ptr = ptr->next;
        output[cnt++] = ptr->data;
    }

    return cnt;
}

void print(){
    int i=0;
    int output[MAX_NODE] = {0, };
    int cnt = getList(output);
    while (cnt--)
        cout << " " << output[i++];
    cout <<"\n";
}

int print2Num(int num){
    int i=0;
    int output[MAX_NODE] = {0, };
    int cnt = getList(output);
    if (cnt <= num) return -1;
    while (cnt--){
        if(i == num) return output[i];
        i++;
    }
}

int main(){

    int T, N, M, L, idx, data;
    char CMD;

    cin >> T;

    for(int t=1; t<=T; t++){

        init();
        cin >> N >> M >> L; //  수열의 길이 N, 추가 횟수 M, 출력할 인덱스 번호 L

        // 수열 추가
        for(int i=0; i<N; i++){
            cin >> data;
            addNode2Tail(data);
        }

        for(int i=0; i<M; i++){
            cin >> CMD;

            switch (CMD)
            {
            case 'I': // I 2 7 -> 2번 인덱스 앞에 7을 추가하고, 한 칸 씩 뒤로 이동한다.
                /* code */
                cin >> idx >> data;
                addNode2Num(data, idx);
                break;
            case 'D': // D 4 -> 4번 인덱스 자리를 지우고, 한 칸 씩 앞으로 이동한다.
                cin >> idx;
                deleteNode2Num(idx);
            break;
            case 'C': // C 3 8 -> 3번 인덱스 자리를 8로 바꾼다.
                cin >> idx >> data;
                changeNode2Num(data, idx);
                break;          
            default:
                break;
            }
        }

        cout << "#" << t << " ";
        cout << print2Num(L) << '\n';
    }

    return 0;
}