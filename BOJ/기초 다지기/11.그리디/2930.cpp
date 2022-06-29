#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 브론즈2

using namespace std;

int get_score(char sanggeun, char friends){
    if (sanggeun == 'R'){
        if (friends == 'S')
            return 2;
        else if (friends == 'R')
            return 1;
        else if (friends == 'P')
            return 0;
    }
    else if (sanggeun == 'S'){
        if (friends == 'P')
            return 2;
        else if (friends == 'S')
            return 1;
        else if (friends == 'R')
            return 0;
    }
    else if (sanggeun == 'P'){
        if (friends == 'R')
            return 2;
        else if (friends == 'P')
            return 1;
        else if (friends == 'S')
            return 0;
    }
}
int main(){

    int R, N;
    string sang, temp;


    cin >> R;
    cin >> sang;

    cin >> N;

    vector<string> friends;

    for(int i=0; i<N; i++){
        cin >> temp;
        friends.push_back(temp);
    }

    
    // 상근이의 점수
    int score = 0, max_score = 0;
    vector<int> score_list;
    for(int j=0; j<R; j++){
        char a = sang[j]; // 원래 상근이가 낸 것
        score_list = {0, 0, 0}; // 주먹, 가위, 보 냈을 떄
        for(int i=0; i<N; i++){
            score += get_score(a, friends[i][j]);
            score_list[0] += get_score('R', friends[i][j]); 
            score_list[1] += get_score('S', friends[i][j]); 
            score_list[2] += get_score('P', friends[i][j]);
        }

        max_score += *max_element(score_list.begin(), score_list.end());

    }
    
    cout << score << '\n';
    cout << max_score << '\n';

    return 0;
}