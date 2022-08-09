#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

constexpr size_t MAX_NODE = 201;

bool now = true; // true면 숫자 false면 연산자
bool result = true;

// 숫자인지 연산자인지
bool isNumber(string str){
    int ascii = (int)str[0];
    // 0 ~ 9 인지
    if (48 <= ascii && ascii <= 57) return true;
    return false;
}

struct Node
{
    string key;
    Node* left, *right;
};

Node node_pool[MAX_NODE];

Node* root = &node_pool[1];

void new_node(int num, string key){
    node_pool[num].key = key;
    node_pool[num].left = nullptr;
    node_pool[num].right = nullptr;
}

void traversal(Node* node){
    if (!result) return;
    if (node->left != nullptr) traversal(node->left);
    bool before = now;
    now = isNumber(node->key);
    if (!now && !before) { // 연산자 + 연산자 
        result = false;
        return;
    }
    if (node->right != nullptr) traversal(node->right);
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


int main(int argc, char** argv)
{
	int test_case;
    int N;
    string cmd;

    // 총 10개의 테스트 케이스가 주어진다.
	for(test_case = 1; test_case <= 10; ++test_case)
	{   
        result = true;
        // 각 테스트 케이스의 첫 줄에는 각 케이스의 트리가 갖는 정점의 총 수 N(1≤N≤200)이 주어진다.
        cin >> N;
        cin.ignore();

        for(int i=0; i<N; i++){
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

        
	
        traversal(root);
        cout << "#" << test_case << " " << result << "\n";

	}
	return 0;
}