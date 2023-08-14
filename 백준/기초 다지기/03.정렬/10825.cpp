#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<string, int, int, int>> student; 

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
// 국어 점수가 같으면 영어 점수가 증가하는 순서로
    if (get<1>(a) == get<1>(b)){
        // 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
        if(get<2>(a) == get<2>(b)){
            // 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
            if(get<3>(a) == get<3>(b)){
                return get<0>(a) < get<0>(b);
            }
            return get<3>(a) > get<3>(b);
        }
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}
int main(){

    int N;

    cin >> N;

    string name; 
    int kor, eng, math; // 국어 영어 수학 

    for (int i=0; i<N; i++){
        cin >> name >> kor >> eng >> math;
        student.push_back({name, kor, eng, math});
    }

    sort(student.begin(), student.end(), compare);

    for (int i=0; i<N; i++){
        cout << get<0>(student[i]) << '\n';
    }
    return 0;

}