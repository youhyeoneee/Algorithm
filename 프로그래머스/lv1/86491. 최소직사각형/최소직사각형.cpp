#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int answer = 0;
    
    int max_x = 0;
    int max_y = 0;
    
    for (vector<int> size : sizes)
    {
        max_x = max(max(size[0], size[1]), max_x);
        max_y = max(min(size[0], size[1]), max_y);
    }

    return max_x * max_y;
}