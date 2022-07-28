#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

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

// 맨 앞에 노드 추가
void addNode2Head(int data)  // 1
{
    Node* node = getNode(data);
    node->next = head->next;
    if (head->next != nullptr) head->next->prev = node;
    head->next = node;
    node->prev = head;
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

    for(int i=1; i<num; i++){
        ptr = ptr->next;

        if(ptr->next == nullptr) break;
    }
    
    node->next = ptr->next;
    if (ptr->next != nullptr) ptr->next->prev = node;
    ptr->next = node;
    node->prev = ptr;

}

// data를 가진 node의 순서를 리턴
int findNode(int data)  // 4
{
    Node* ptr = head;
    int cnt = 1;
    while(ptr->next != nullptr && ptr->next->data != data){
        ptr = ptr->next;
        cnt++;
    }

    if (ptr->next == nullptr) return 0;
    else return cnt;
}

// data를 가진 노드를 삭제
void removeNode(int data) // 5
{
    Node* prev_ptr = head;
    while(prev_ptr->next != nullptr && prev_ptr->next->data != data){
        prev_ptr = prev_ptr->next;
    }

    if (prev_ptr->next != nullptr){
        Node* curr_ptr = prev_ptr->next;
        prev_ptr->next = curr_ptr->next;
        if (curr_ptr->next != nullptr)
            curr_ptr->next->prev = prev_ptr;
    }

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

// 노드의 data 정보를 역순으로 output[]에 저장하고 노드 개수를 리턴
int getReversedList(int output[MAX_NODE])  // 7
{
    Node* ptr = head;
    int cnt = 0;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    while(ptr->prev != nullptr){
        output[cnt++] = ptr->data;
        ptr = ptr->prev;
    }

    return cnt;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("dll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}