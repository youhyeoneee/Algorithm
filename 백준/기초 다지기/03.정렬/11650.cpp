#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
vector<pair<int, int>> dot;

int main(){

    int N;
    cin >> N;
    int x, y;
    // 좌표 입력 
    for (int i=0; i<N; i++){
        cin >> x >> y;
        dot.push_back({x, y});
    }
    
    // 구현
    sort(dot.begin(), dot.end());

    // 좌표 출력 
    for (int i=0; i<N; i++){
        cout << dot[i].first << ' ' << dot[i].second << '\n';
    }

    return 0;
}