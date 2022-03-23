#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<pair <int, int>> dot;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}


int main(){
    int N, x, y;
    cin >> N;

    // 입력
    for(int i=0; i<N; i++){
        cin >> x >> y;
        dot.push_back({x, y});
    }

    sort(dot.begin(), dot.end(), compare);

    // 출력
    for(int i=0; i<N; i++){
        cout << dot[i].first << " " << dot[i].second << '\n';
    }
    return 0;
}