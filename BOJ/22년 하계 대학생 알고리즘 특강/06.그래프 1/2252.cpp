#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int arr[10000][2]; // 간선 리스트
int student[320001][2]; // 정점, 진입차수
queue<int> q;

int main(){

    cin >> N >> M;
    // M은 키를 비교한 회수
    for(int i=0; i<M; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    // 초기화
    for(int i=1; i<=N; i++)
        student[i][0] = i;

    // 진입 차수
    for(int i=0; i<M; i++){
        int tmp = arr[i][1];
        student[tmp][1]++; // 뒤에 서야 하는 학생들 줄 세우기
    }
    
    for(int i=0; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(student[j][1] == i) q.push(student[j][0]);
        }
    }
    
    for(int i=0; i<N; i++){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}