#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

#define INF 1e15

using namespace std;

bool isDivisible(long long xNumerator, long long yNumerator, long long denominator) {
    return xNumerator % denominator == 0 && yNumerator % denominator == 0;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long, long long>> meets; 
    
    for(int i=0; i<line.size()-1; i++) {
        for(int j=i+1; j<line.size(); j++) {
            long long a = line[i][0], b = line[i][1], e = line[i][2];
            long long c = line[j][0], d = line[j][1], f = line[j][2];
            
            long long denominator = a*d - b*c;

            if (denominator == 0) {
                continue;
            } else {
                long long xNumerator = b*f - e*d;                
                long long yNumerator = e*c - a*f;
                
                if (isDivisible(xNumerator, yNumerator, denominator)) {
                    long long x = xNumerator / denominator;
                    long long y = yNumerator / denominator;
                    
                    meets.insert({x, y});
                }
            }
        }
    }
    
    long long minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    
    for(auto i : meets) {        
        minX = min(i.first, minX);
        maxX = max(i.first, maxX);
        
        minY = min(i.second, minY);
        maxY = max(i.second, maxY);
    }

    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    
    char map[height][width];
    
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            map[i][j] = '.';
        }
    }
    
    for(auto i : meets) { 
        map[maxY-i.second][i.first-minX] = '*';
    }
    
    for(int i=0; i<height; i++) {
        string str = "";
        for(int j=0; j<width; j++) {
            str += map[i][j];
        }
        answer.push_back(str);
    }
    
    
    return answer;
}