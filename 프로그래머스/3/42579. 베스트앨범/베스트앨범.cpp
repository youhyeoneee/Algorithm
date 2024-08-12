#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compareGenre(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

// 재생횟수 > 우선순위 
bool comparePlaylist(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르 - 재생횟수 
    map<string, int> genrePlaycnt;
    
    // 장르 - <고유번호, 재생횟수> 
    map<string, vector<pair<int, int>>> genrePlaylist;

    for(int i=0; i<genres.size(); i++) {
        string genre = genres[i];
        genrePlaycnt[genre] += plays[i];
        genrePlaylist[genre].push_back({i, plays[i]});
    }
    
    // 정렬 위해 벡터로 변환 
    vector<pair<string, int>> v(genrePlaycnt.begin(), genrePlaycnt.end());
    sort(v.begin(), v.end(), compareGenre);
    
    for(auto m : v) {
        string genre = m.first; 
        sort(genrePlaylist[genre].begin(), genrePlaylist[genre].end(), comparePlaylist);
        
        int cnt = min(2, (int)genrePlaylist[genre].size());
                      
       for(int i=0; i<cnt; i++) {
           answer.push_back(genrePlaylist[genre][i].first);
       }
    }    
    
    return answer;
}