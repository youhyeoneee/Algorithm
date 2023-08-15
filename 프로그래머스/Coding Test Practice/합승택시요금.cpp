#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INF 20000000

int minCostArr[204][204];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = INF;
    
    // 배열 초기화
    fill(&minCostArr[0][0], &minCostArr[0][0] + 204 * 204, INF);
    
    // 그래프 초기화
    for(vector<int> v : fares)
    {
        minCostArr[v[0]][v[1]] = v[2];
        minCostArr[v[1]][v[0]] = v[2];
    }
    
    // 자기 자신~자기자신 = 0 
    for(int i=1; i<=n; i++)
    {
        minCostArr[i][i] = 0;
    }
    

    // 플로이드 알고리즘 핵심 200 * 200 * 200 = 40,000,000
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if (minCostArr[i][j] > minCostArr[i][k] + minCostArr[k][j])
                    minCostArr[i][j] = minCostArr[i][k] + minCostArr[k][j];
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (minCostArr[i][j] == INF) cout << "- ";
            else cout << minCostArr[i][j] << " ";
        }
        cout << '\n';
    }
    // 답 도출 s~i + i~a + i~b 가 최소인 것
    for(int i=1; i<=n; i++)
    {        
        if (answer > minCostArr[s][i] + minCostArr[i][a] + minCostArr[i][b])
        {
            cout << "s : " << s << ", i : " << i << " a : " << a << " , b : " << b << '\n';
            answer = minCostArr[s][i] + minCostArr[i][a] + minCostArr[i][b];
            cout << minCostArr[s][i] << "+" << minCostArr[i][a] << "+" << minCostArr[i][b] << "=" << answer << '\n';

        }
    }
    
    return answer;
}

int main()
{
    cout << solution(7, 3, 4, 1, {{5, 7, 9},{4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}});
}