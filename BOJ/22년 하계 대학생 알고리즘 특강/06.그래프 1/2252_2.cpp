#include <vector> // 인접 리스트 : 정점 별로 크기가 다르므로 동적 배열(리스트)로 작성 예정
#include <deque> // In-degree가 0이 되는 정점을 push/pop 하는 자료구조 공간
#include <iostream>

// 줄세우기

using namespace std;

int N, M, a, b;

vector<int> AL[32001]; // 인접 리스트 : 학생 수가 최대 32000명이므로
int InDegree[32001]; // 해당 정점에 대한 In-degree 차수를 저장

int Answer[32001], idx; // 프로그래머 스타일에 따라 사용 할지 안할지 판단.

int main(){

    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> a >> b;
        AL[a].push_back(b); // 방향성 있는 간선이므로 한 곳만 추가
        ++InDegree[b]; // a->b 이므로 b의 In-degree 증가
    }

    // processing
    deque<int> q; // In-degree 0이 되는 정점 저장 자료구조
    for(int i=1; i<=N; i++){
        if(!InDegree[i]) q.push_back(i);
    }

    while(!q.empty()){ // q에 남아있는 정점이 하나도 없을 때까지 계속 진행
        int curr = q.front();
        q.pop_front(); // q에 저장되어 있는 정점을 하나 꺼내고 인접 정점 비교
        Answer[idx++] = curr;
        for(int next : AL[curr]){ // curr가 화살을 쏘아 맞는 정점 탐색, for-each로 하나씩 불러냄
            if(!--InDegree[next]) q.push_back(next); // 1 뺐을 때 InDegree가 0이 되면 q에 넣기
        }
    }

    cout << Answer[0];
    for(int i=1; i<idx; i++)
        cout << " " << Answer[i];


    return 0;

}