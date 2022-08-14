#include <iostream>
#include <string>
#include <map>
#include <vector>


// 0 / 10 (오답)

using namespace std;

string a, b;

map<char, vector<int>> a_map; 

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        // INPUT
        cin >> a >> b;

        // a의 문자열로 map 만들기
        for(char ch : a){
            a_map[ch] = {};
        }


        // 공통되는 문자의 index만 push
        for(int i=0; i<b.size(); i++){
            if (a_map.count(b[i])){
                a_map[b[i]].push_back(i);
            }
        }   

        int a_idx = 0, b_idx = 0;

        int length = 0;
        for(a_idx; a_idx<a.size(); a_idx++){
            char a_curr = a[a_idx];

            // 공통되는 문자가 아님
            if (!a_map[a_curr].size())  continue;

            // 공통되는 문자일 경우
            for(int i : a_map[a_curr]){
                if (i > b_idx){
                    b_idx = i;
                    length++;
                    break;
                }
            }

        }

        cout << "#" << test_case << " " << length << "\n";

        // INIT 

        a_map.clear(); 

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}