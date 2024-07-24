#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[1001][1001];

// 하, 우, 좌상
int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};

bool isEnd(int x, int y, int n) {
    int cnt = 0;
    
    for(int i=0; i<3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx]) {
            cnt++;
        } else  if (i == 1 && y == x) { // 모서리 대각선 변에 걸친 경우 우측은 무조건 비어있으므로 이를 처리
            cnt++;
        }
    }
    
    return cnt == 3;
}


vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1;
    int dir = 0;
    int x = 0, y = 0;
    
    while(true) {        
        // 채우고 
        map[y][x] = num++;
    
        // 더 갈 수 있는 곳이 있는지 확인 후 없으면 끝내기
        if (isEnd(x, y, n)) break;
    
        // 이동 시켜보기 
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        // 닿았으면 방향 바꿈 
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx]) {
            dir = (dir+1) % 3;
        } 
        
        y = y + dy[dir];
        x = x + dx[dir];   
    }
    
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            answer.push_back(map[i][j]);
        }
    }
    
    return answer;
}