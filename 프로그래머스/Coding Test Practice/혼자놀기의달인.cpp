#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;


int cnt = 0;
vector<int> cntVec;
bool visited[104];

// open 상자
void OpenBox(int n, vector<int> &cards)
{
    int idx = n-1;
    // 상자가 열려있지 않으면 상자를 열고 재귀
    if (!visited[idx])
    {
        visited[idx] = true;
        int target = cards[idx]; // 0 -> 8
        OpenBox(target, cards);
        cnt++;
    }
    
    return;
}


int solution(vector<int> cards) {
    int answer = 0;
    int box1, box2;
    
    for(int i=1; i<=cards.size(); i++)
    {
        memset(visited, 0, sizeof(visited)); // 방문 배열 초기화 
        OpenBox(i, cards);
        box1 = cnt;
        cnt = 0; 
        
        cout << "box 1 : " << box1 << '\n';
        for(int j=1; j<=cards.size(); j++)
        {
            if (!visited[j-1])
            {
                OpenBox(j, cards);
                box2 = cnt;
                cnt = 0; 

                cout << "box 2 : " << box2 << '\n';
                answer = max(box1*box2, answer);
                cout << "box1 * box2 = " << box1*box2 << '\n';
                cout << "anwser : " << answer << '\n'; 
            }
        }
        
    }
  

    return answer;
}

int main()
{
    vector<int> cards = {8,6,3,7,2,5,1,4};

    cout << solution(cards);
}