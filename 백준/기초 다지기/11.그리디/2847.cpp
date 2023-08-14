#include <iostream>
#include <vector>

using namespace std;

// 실버 4

int main(){

    int N, temp;

    vector<int> score_list;

    cin >> N;
    for (int i=0; i<N; i++){   
        cin >> temp;
        score_list.push_back(temp);
    }

    int score = score_list[N-1], result = 0; // 맨 어려운 레벨의 점수 저장

    for(int i=N-2; i>=0; i--){ // 어려운 레벨부터
        if (score_list[i] >= score){
            result += (score_list[i] - score + 1);
            score--;
        }
        else    
            score = score_list[i];
    }

    cout << result << '\n';


    return 0;
}