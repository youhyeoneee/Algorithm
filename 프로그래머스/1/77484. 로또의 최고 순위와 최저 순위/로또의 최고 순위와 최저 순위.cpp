#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isWinNum(int num, vector<int> win_nums) {
    for(int win : win_nums) {
        if (num == win) 
            return true;
    }
    return false;
}

// 정답 개수 - 랭크 
int ranks[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
        
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int zeroCnt = 0;
    int winCnt = 0;
    
    for(int lotto : lottos) {
        if (lotto == 0) {
            zeroCnt++;
        } else if (isWinNum(lotto, win_nums)) {
            winCnt++; 
        }
    }
    
    int maxRank = ranks[zeroCnt + winCnt];
    int minRank = ranks[winCnt];
   
    answer.push_back(maxRank);
    answer.push_back(minRank);
    
    return answer;
}