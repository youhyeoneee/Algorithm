#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 50;
bool visited[50];

bool CanChange(string a, string b)
{
    int cnt = 0;
    for(int i=0; i<a.length(); i++)
    {
        if (a[i] != b[i]) cnt++;
    }
    
    return (cnt == 1);
}

void Dfs(string current, int cnt, string &target, vector<string> &words)
{
    // 변환 끝
    if (current == target)
    {
        // 최솟값 갱신
        answer = min(answer, cnt);
        return;
    }
    
    // 최솟값 아닌 경우 탐색 그만 
    if (cnt > answer)
    {
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        if (!visited[i] && CanChange(words[i], current))
        {
            visited[i] = true;
            Dfs(words[i], cnt+1, target, words);
            visited[i] = false;
        }

    }
}


int solution(string begin, string target, vector<string> words) {
    
    Dfs(begin, 0, target, words);
    
    if (answer == 50) answer = 0;
    
    return answer;
}