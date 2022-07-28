#define MAX_NODE 10000
#include <iostream>

using namespace std;


struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

// 추가
Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

// 초기화
void init()
{
    head = getNode(-1);
    head->next = nullptr;
}

// 맨 앞에 노드 추가
void addNode2Head(int data) 
{
    Node* node = getNode(data);
    node->next = head->next;
    head->next = node;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
    Node* node = getNode(data);
    Node* ptr = head;
    while(ptr->next != nullptr){ 
        ptr = ptr->next;
    }

    node->next = ptr->next;
    ptr->next = node;
}

// 지정된 순서(num)에 노드 추가 (1-2-3-4-5-...)
void addNode2Num(int data, int num) 
{

    Node* node = getNode(data);
    Node* ptr = head;
    for(int i=1; i<num; i++){
        ptr = ptr->next;
    }

    node->next = ptr->next;
    ptr->next = node;

}

// 주어진 data 값을 가진 노드 삭제
void removeNode(int data) 
{   

    Node* prev_ptr = head;
    while(prev_ptr->next != nullptr && prev_ptr->next->data != data){ 
        prev_ptr = prev_ptr->next;
    }

    if (prev_ptr->next != nullptr){
        prev_ptr->next = prev_ptr->next->next;
    }

}

// output[] 배열에 리스트 노드의 data를 차례로 넣고, 총 노드 갯수를 리턴
int getList(int output[MAX_NODE]) 
{
    Node* ptr = head;
    int cnt = 0;
    while(ptr->next != nullptr){ 
        ptr = ptr->next;
        output[cnt++] = ptr->data;
    }

    return cnt;
}

void print() 
{   
    cout << "print\n";
    Node* ptr = head->next;
    while(ptr != nullptr){ 
        cout << ptr->data << " ";
        if (ptr->next != nullptr)
            cout << "->";
        ptr = ptr->next;
    }
    cout << '\n';
}


int main(){

    init();
    addNode2Head(2);
    print();
    addNode2Tail(3);
    print();
    addNode2Num(4, 2);
    print();
    removeNode(6);
    print();
    int output[MAX_NODE];
    cout << getList(output);
    return 0;
}