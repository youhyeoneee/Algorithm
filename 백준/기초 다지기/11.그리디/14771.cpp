#include <iostream>
#include<algorithm>
#include<vector>

// 브론즈2 

using namespace std;


int main(){

    int N, M, A, B, giveaway = 0, result = 0; // 경품 개수, 비용 

    cin >> N >> M;
    vector<int> points;
    for (int i=0; i<M; i++){
        cin >> A >> B;
        points.push_back(A);
    }

    // 정렬
    sort(points.begin(), points.end(), greater<int>());

    for (int i=0; i<M; i++){
        if (points[i]>=N){ // 당첨 경품 
            giveaway++;
        }  
        else{ 
            result += ((N)-points[i]);
            giveaway++;
        }

        if (giveaway == M-1) // 다 가졌으면 탈출 
            break;
        
    }

    cout << result << '\n';
    return 0;
}