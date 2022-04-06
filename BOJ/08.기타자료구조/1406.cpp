#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string S; //  초기에 편집기에 입력되어 있는 문자열 (길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.)
    cin >> S;

    // 커서를 기준으로 왼쪽 stack, 오른쪽 stack을 선언한다.
    stack<char> l;
    stack<char> r;

    for (int i=0; i<S.length(); i++){
        l.push(S[i]);
    }

    int M; // 입력할 명령어의 개수를 나타내는 정수 
    cin >> M; 

    string cmd; // 명령어 
    for (int i=0; i<M; i++){
        cin >> cmd;
        // L: 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
        if (cmd.find('L') == 0){
            if (!l.empty()){
                r.push(l.top());
                l.pop();
            }
        }
        // D: 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
        else if(cmd.find('D') == 0){
            if (!r.empty()){
                l.push(r.top());
                r.pop();
            }
        }
        // B: 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
        //    삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
        else if (cmd.find('B') == 0){
            if (!l.empty())
                l.pop();
        }
        // P x : x라는 문자를 커서 왼쪽에 추가함
        else if (cmd.find('P') == 0){
            char x; // P x 
            cin >> x;
            l.push(x);
        }
    }

    // 결과 프린트
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }
    
    cout << '\n';
    return 0;
}