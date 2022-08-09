#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

constexpr size_t MAX_NODE = 101;

struct Node {
	string key;
	Node *left, *right;
};


Node node_pool[MAX_NODE];

// 루트 노드를 가리키는 포인터
Node* root = &node_pool[1];

void new_node(int num, string key) {
	node_pool[num].key = key;
	node_pool[num].left = nullptr;
	node_pool[num].right = nullptr;
}


void traversal_rec(Node* node) {
	if (node->left != nullptr) traversal_rec(node->left);
	cout << node->key; 
	if (node->right != nullptr) traversal_rec(node->right);
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int main(){

    int N, num, left, right;
    char data;
    string cmd;

    for(int TC=1; TC<=10; TC++){

        cin >> N;
        cin.ignore();

        for(int i=1; i<=N; i++){
            getline(cin, cmd);
            vector<string> string_vec;
            string_vec = split(cmd, ' ');

            if (string_vec.empty()) continue;

            int idx = stoi(string_vec[0]); // 노드 번호
            new_node(idx, string_vec[1]); // 노드 번호에 문자 넣기
            if (string_vec.size() > 2) { // 왼쪽 자식 노드 번호
                node_pool[idx].left = &node_pool[stoi(string_vec[2])];
            }
            if (string_vec.size() > 3) { // 오른쪽 자식 노드 번호
                node_pool[idx].right = &node_pool[stoi(string_vec[3])];
            }
        }

        
        cout << "#" << TC << " ";
        traversal_rec(root);
        printf("\n");
    }

    return 0;
}