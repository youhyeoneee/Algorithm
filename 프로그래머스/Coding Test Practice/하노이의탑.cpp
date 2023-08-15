#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int start, int mid, int dest, int n)
{
    if (n == 0)
        return;
    
    Hanoi(start, dest, mid, n-1);
    answer.push_back({start, dest});
    Hanoi(mid, start, dest, n-1);
}

vector<vector<int>> solution(int n) {
    
    // 1->2 : n-1개의 원판을 옮긴다. 1에는 가장 큰 n번째 원판만 남게 된다.
    // 1->3 : 가장 큰 n번째 원판을 옮긴다.
    // 2->3 : n-1개의 원판을 옮긴다.
    
    Hanoi(1, 2, 3, n);
    
    return answer;
}

int main()
{
    for (auto v : solution(2))
    {
        for(auto i : v)
            cout << i << " ";

        cout << "\n";
    };
}