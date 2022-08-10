#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <deque>

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define MAX 50000

// 3/10 통과 (시간초과) 

using namespace std;

struct Node
{
    string name;
    vector<Node> child; // 같은 상위 디렉터리를 가지는 디렉터리는 30 개 이하이다.   
};

int node_count = 0;
Node node_pool[MAX]; // 정적 할당
Node* root;

unordered_map<string, int> directory_map; // 디렉토리 이름 - 번호 매핑

void print(){

    cout << ">>> every directory \n";
    for(auto i : directory_map){
        cout << ">> " << i.first << "(" << i.second << ")\n";
    }
}

// delimiter를 기준으로 문자열 나누는 함수
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        if (temp != "\0") answer.push_back(temp);
    }
 
    return answer;
}

// 맨 하위 폴더 = 0 / 그 위 폴더 = 1
// ex.  /aa/cc/ 
// 0 -> cc
// 1 -> aa
string get_directory_name(char path[PATH_MAXLEN + 1], int type){
    vector<string> v;  
    v = split(path, '/');
    int vec_size = v.size();

    if (vec_size > 0){
        if (type == 1 && vec_size > 1) {
            return v[vec_size-2];
        }
        else if (type == 0) return v[vec_size-1];
    }
    return "/";
}

void init(int n) {
// 각 testcase 시작 시, 초기화를 위해 1번 호출되고 루트 디렉터리를 생성한다.
// Parameters
// n: 이번 testcase에서 루트 디렉터리를 포함하여 생성되는 최대 디렉터리의 개수 (5 ≤ n ≤ 50,000)
    
    node_count = 0;

    // 루트 노드 생성
    root = &node_pool[node_count];
    root->name = "/";
    root->child.clear();

    directory_map["/"] = node_count;
    node_count++;
    // cout << ">> init \n";
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
// path[] 디렉터리의 하위에 name[] 이름을 가진 새로운 디렉터리를 생성한다.

// Parameters
// path[2000]: 생성할 디렉터리의 상위 디렉터리의 경로 (1 ≤ length ≤ 1,999)
// name[7]: 생성할 디렉터리의 이름 (2 ≤ length ≤ 6)

    // 노드 생성
    directory_map[name] = node_count;
    node_pool[node_count].name = name;
    node_pool[node_count].child.clear();

    // 부모 - 자식 설정

    int parent = directory_map[get_directory_name(path, 0)];

    node_pool[parent].child.push_back(node_pool[node_count]);

    // cout << ">> parent : " << path << "\n";
    // cout << ">> child list : ";
    // for(auto i : node_pool[parent].child){
    //     cout << i.name << " ";
    // }
    // cout << '\n';

    node_count++;
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
// path[] 디렉터리와 그 모든 하위 디렉터리를 삭제한다.

// Parameters
// path[2000]: 삭제할 디렉터리의 경로 (1 ≤ length ≤ 1,999)
    int parent = directory_map[get_directory_name(path, 1)];
    string child_name = get_directory_name(path, 0);

    for(auto iter = node_pool[parent].child.begin(); iter != node_pool[parent].child.end(); ++iter){
        if(iter->name == child_name){
            iter = node_pool[parent].child.erase(iter);
            break;
        }
    } 
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
// dstPath[] 디렉터리의 하위에 srcPath[] 의 디렉터리와 그 모든 하위 디렉터리를 복사한다.

// Parameters
// srcPath[2000]: 복사할 디렉터리의 경로 (1 ≤ length ≤ 1,999)
// dstPath[2000]: srcPath[] 디렉터리가 복사 될 위치의 상위 디렉터리 경로 (1 ≤ length ≤ 1,999)
    int new_parent = directory_map[get_directory_name(dstPath, 0)];
    int before_parent = directory_map[get_directory_name(srcPath, 1)];
    int child = directory_map[get_directory_name(srcPath, 0)];

    // 새로운 부모로 이동
    node_pool[new_parent].child.push_back(node_pool[child]);

    // cout << ">> parent : " << dstPath << "\n";
    // cout << ">> child list : ";
    // for(auto i : node_pool[new_parent].child){
    //     cout << i.name << " ";
    // }
    // cout << '\n';
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
// dstPath[] 디렉터리의 하위에 srcPath[] 의 디렉터리와 그 모든 하위 디렉터리를 이동한다.
// Parameters
// srcPath[2000]: 이동할 디렉터리의 경로 (1 ≤ length ≤ 1,999)
// dstPath[2000]: srcPath[] 디렉터리가 이동 될 위치의 상위 디렉터리 경로 (1 ≤ length ≤ 1,999)

    int new_parent = directory_map[get_directory_name(dstPath, 0)];
    int before_parent = directory_map[get_directory_name(srcPath, 1)];
    string child_name = get_directory_name(srcPath, 0);
    int child_idx = directory_map[child_name];

    // 기존 부모에게서 자식을 제거
    for(auto iter = node_pool[before_parent].child.begin(); iter != node_pool[before_parent].child.end(); ++iter){
        if(iter->name == child_name){
            iter = node_pool[before_parent].child.erase(iter);
            break;
        }
    }

    // 새로운 부모로 이동
    node_pool[new_parent].child.push_back(node_pool[child_idx]);

    // cout << ">> parent : " << srcPath << "\n";
    // cout << ">> child list : ";
    // for(auto i : node_pool[before_parent].child){
    //     cout << i.name << " ";
    // }

    // cout << '\n';

    // cout << ">> parent : " << dstPath << "\n";
    // cout << ">> child list : ";
    // for(auto i : node_pool[new_parent].child){
    //     cout << i.name << " ";
    // }
    // cout << '\n';
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
// path[] 디렉터리의 모든 하위 디렉터리 개수를 반환한다.

// Parameters
// path[2000]: 디렉터리의 경로 (1 ≤ length ≤ 1,999)

// Return
// path[] 디렉터리의 모든 하위 디렉터리 개수
    string name = get_directory_name(path, 0);
    // cout << ">> " << name << "\n";
    int start = directory_map[get_directory_name(path, 0)];

    deque<int> q;
    int subtree_size = -1;

    bool visited[MAX] = {false, };

    q.push_back(start); // 탐색의 시작은 root
    while(!q.empty()){
        int curr = q.front(); 
        q.pop_front();
        visited[curr] = true;

        subtree_size++;
        for(auto next : node_pool[curr].child){
            // cout << next.name << "\n";
            int idx = directory_map[next.name];
            if(!visited[idx]){ // 자식이면
                q.push_back(idx);
            }
        }
    }


    // cout << "subtree size : " << subtree_size << "\n";
	return subtree_size;
}

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}

        print();
	}

	return isAccepted;
}


int main(void) {

	int test, T;
	int n, m;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}