#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르 - <고유번호, 재생횟수> 
    // 장르 내 정렬 : 재생횟수 > 고유번호 별 
    // 장르 - 재생횟수 정렬
    // 순서대로 합치기 
    map<string, int> genrePlayCnt;
    map<string, vector<pair<int, int>>> genrePlayDetail;

    for(int i=0; i<genres.size(); i++) {
        genrePlayCnt[genres[i]] += plays[i];
        genrePlayDetail[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> v(genrePlayCnt.begin(), genrePlayCnt.end());
    sort(v.begin(), v.end(), compare);
    
    for(auto m : v) {
        string genre = m.first; 
        vector<pair<int, int>> numberPlayCnt = genrePlayDetail[genre];
        sort(numberPlayCnt.begin(), numberPlayCnt.end(), compare2);
        
        int cnt = min(2, (int)numberPlayCnt.size());
                      
       for(int i=0; i<cnt; i++) {
           answer.push_back(numberPlayCnt[i].first);
       }
    }    
    
    return answer;
}