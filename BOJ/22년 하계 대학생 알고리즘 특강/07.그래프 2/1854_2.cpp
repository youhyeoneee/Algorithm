#include <cstdio>
#include <queue>
#include <vector>

// K번째 최단 경로

struct n_t {
    int noed;
    int cost;
    bool operator<(const n_t & ref) const{
        return this->cost > ref.cost;
    }
};

int N, M, K;

std::vector<n_t> AL[1001];
std::priority_queue<int> Visited[1001];
std::priority_queue<n_t> PQ;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    int a, b, c;
    for(int i=1; i<=M; i++){
        scanf("%d %d %d", &a, &b, &c);
        AL[a].push_back({b, c});
    }

    Visited[1].push(0);
    PQ.push({1, 0});
    while(!PQ.empty()){
        n_t curr = PQ.top();
        PQ.pop();
        for(n_t next: AL[curr.node]){
            int ncost = curr.cost + next.cost;
        }
    }


}
