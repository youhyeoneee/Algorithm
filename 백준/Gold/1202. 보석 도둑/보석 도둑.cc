#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;

using namespace std;

ll N, K, W, P, C, result;

vector<pair<ll, ll>> gemVec; // 보석 : 무게, 가격
vector<ll> bagVec; // 가방 : 무게 

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void Input()
{
    cin >> N >> K;

    // 보석
    for(int i=0; i<N; i++)
    {   
        cin >> W >> P;
        gemVec.push_back({W, P});        
    }

    // 가방 
    for(int i=0; i<K; i++)
    {
        cin >> C;
        bagVec.push_back(C);
    }
}

void Solve()
{

    // 오름차순 정렬
    sort(gemVec.begin(), gemVec.end());
    sort(bagVec.begin(), bagVec.end());

    priority_queue<ll> pq;

    int gemIdx=0; 

    // 가방 개수만큼 
    for(int i=0; i<K; i++)
    {   
        // 최대 무게 내에 넣을 수 있는 보석 다 넣기 (어짜피 이번 가방에 담을 수 있는 건 다음 가방에도 담을 수 있음!)
        // pq 사용 이유 : N의 크기가 너무 크기 때문에
        while(gemIdx < N && gemVec[gemIdx].first <= bagVec[i]) 
        {
            pq.push(gemVec[gemIdx].second);
            gemIdx++;
        }

        if (pq.size())
        {
            // 가격 제일 높은 것 1개 빼기
            result += pq.top();
            pq.pop();
        }
    }


    cout << result;

}

int main()
{
    FastIO();
    Input();
    Solve();
}