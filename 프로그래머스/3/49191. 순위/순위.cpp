#include <string>
#include <vector>
#include <iostream>
#include <cstring>

#define MAX 100+4
#define INF 98754321

using namespace std;

int adj[MAX][MAX];



int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            adj[i][j] = INF;
        }
    }
    
    for(int i=1; i<=n; i++) {
        adj[i][i] = 0;
    }
    
    for(vector<int> result : results) {
        int winner = result[0], loser = result[1];
        
        adj[winner][loser] = 1; 
        adj[loser][winner] = -1; 
    }

    for(int k=1; k<=n; k++) {
        for(int j=1; j<=n; j++) {
            for(int i=1; i<=n; i++) {
                if (adj[i][k] == 1 && adj[k][j] == 1) {
                    adj[i][j] = 1; 
                    adj[j][i] = -1;
                }
            }
        }
    }
    

    for(int i=1; i<=n; i++) {   
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if (i != j && adj[i][j] != INF) cnt++;
        }
        
        if (cnt == n-1) answer++;
    }
    
    return answer;
}