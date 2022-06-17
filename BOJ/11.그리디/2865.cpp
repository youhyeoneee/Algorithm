#include <iostream>
#include <vector>

using namespace std;

// 실버 4

int main(){

    int N, M, K;

    cin >> N >> M >> K; // 참가자 수, 장르 수, 본선 진출 수

    vector<vector<pair<int, float>>> v;
    for (int i=0; i<M; i++){
        vector<pair<int, float>> temp;
        for (int j=0; j<N; j++){
                pair<int, float> p;
                cin >> p.first >> p.second;
                temp.push_back(p);                
        }
        v.push_back(temp);
    }

    int cnt = 0;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
                cout << v[i][j].first << "," << v[i][j].second << ' ';          
        }
        
    }

    return 0;
}