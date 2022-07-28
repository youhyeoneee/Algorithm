#include <iostream>
#include <vector>
#define MAX_NODE 100000

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

// 새 노드 생성
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


// 지정된 순서(num)에 노드 m개 추가 (1-2-3-4-5-...)
void addNode2Num(vector<int> data_list, int num) 
{
    Node* ptr = head;
    for(int i=0; i<num; i++){
        ptr = ptr->next;
    }

    for(int data : data_list){
        Node* node = getNode(data);
        node->next = ptr->next;
        ptr->next = node;
        ptr = ptr->next;
    }
}


// 지정된 순서(start)부터 노드 num개 삭제 (1-2-3-4-5-...)
void deleteNode2Num(int start, int num) 
{
    Node* prev_ptr = head;

    for(int i=0; i<start; i++){
        prev_ptr = prev_ptr->next;
        if (prev_ptr == nullptr) break;
    }

    Node* next_ptr = prev_ptr;

    for(int i=0; i<num; i++){
        next_ptr = next_ptr->next;
        if (next_ptr == nullptr) break;
    }

    if (next_ptr->next != nullptr){
        prev_ptr->next = next_ptr->next;
    }
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

void print() 
{   
    Node* ptr = head->next;
    int cnt = 0;
    while(ptr != nullptr && cnt < 10){ 
        cout << ptr->data << " ";
        ptr = ptr->next;
        cnt++;
    }
    cout << '\n';
}


int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);


    int N, M, data, x, y;
    char CMD;
    int arr[MAX_NODE];

    // 총 10개의 테스트 케이스
    for(int TC=1; TC<=10; TC++){
        
        init();

        cin >> N; // 원본 암호문의 길이 N ( 2000 ≤ N ≤ 4000 의 정수)
        
        // 원본 암호문
        for(int i=0; i<N; i++){
            cin >> data;
            addNode2Tail(data);
        }

        cin >> M; // 명령어의 개수 ( 250 ≤ M ≤ 500 의 정수)

        for(int i=0; i<M; i++){
            cin >> CMD;

            switch (CMD) {
                case 'I': {// I(삽입) x, y, s : 앞에서부터 x의 위치 바로 다음에 y개의 숫자를 삽입한다. s는 덧붙일 숫자들이다.[ ex) I 3 2 123152 487651 ]
                    cin >> x >> y;
                    vector<int> data_list;
                    for(int j=0; j<y; j++){
                        cin >> data;
                        data_list.push_back(data);
                    }
                    addNode2Num(data_list, x);
                    break;
                }
                case 'D': // D(삭제) x, y : 앞에서부터 x의 위치 바로 다음부터 y개의 숫자를 삭제한다.[ ex) D 4 4 ]
                    cin >> x >> y;
                    deleteNode2Num(x, y);
                    break;
                case 'A': //A(추가) y, s : 암호문의 맨 뒤에 y개의 숫자를 덧붙인다. s는 덧붙일 숫자들이다. [ ex) A 2 421257 796813 ]
                    cin >> y;
                    for(int j=0; j<y; j++){
                        cin >> data;
                        addNode2Tail(data);
                    }
                    break;
   
            }

        }

        cout << "#" << TC << " ";
        print();


    }
   
    return 0;
}