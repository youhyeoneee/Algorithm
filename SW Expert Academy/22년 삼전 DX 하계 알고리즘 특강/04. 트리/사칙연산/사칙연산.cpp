#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

constexpr size_t MAX_NODE = 1001;

stack<float> calcul_stack;

// 숫자인지 연산자인지
bool isNumber(string str){
    if (str == "+" || str == "-" ||str == "*" ||str == "/") return false;
    return true;
}

void calculate(string str){
    float num1 = calcul_stack.top();
    calcul_stack.pop();
    float num2 = calcul_stack.top();
    calcul_stack.pop();
    float result;


    if (str == "+") result = num2 + num1;
    else if (str == "-") result = num2 - num1;
    else if (str == "*") result = num2 * num1;
    else if (str == "/") result = num2 / num1;

    calcul_stack.push(result);
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

void traversal(Node* node){ // post-order
    if (node->left != nullptr) traversal(node->left);
    if (node->right != nullptr) traversal(node->right);
    if(!isNumber(node->key)) { // 연산자일 경우
        calculate(node->key);
    }
    else {  // 숫자일 경우
        calcul_stack.push(stof(node->key));
    }
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


        double div = 0.0;
        cout << "#" << test_case << " " << (int)calcul_stack.top()<< "\n";

        calcul_stack.pop();
	}
	return 0;
}