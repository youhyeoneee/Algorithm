// K번째 최단경로 Core 코드


// Dijkstra 알고리즘 부분에서

struct n_t {
    int node;
    int cost;
    bool operator<(const n_t & ref) const {
        return this->cost > ref.cost;
    }
};

std::vector<n_t> AL[1001];
std::priority_queue<int> visited[1001];
std::priority_queue<n_t> PQ;

// in main function
visited[1].push(0);
PQ.push({ 1, 0 });
while (!PQ.empty()) {
    n_t curr = PQ.top();
    PQ.pop();
    for (n_t next : AL[curr.node]) {
        int ncost = next.cost + curr.cost;
        if (visited[next.node].size() == K && ncost < visited[next.node].top()) {
            visited[next.node].pop();
        }
        if (visited[next.node].size() < K) {
            visited[next.node].push(ncost);
            PQ.push({ next.node, ncost });
        }
    }
}


// visited 에 우선순위큐(최대힙) 을 적용한 이유는..
// Dijkstra 알고리즘 로직에서 visited 에 값을 넣는 시점이 PQ에서 꺼내어질 때가 아니라 PQ 에 값이 들어갈 때이므로
// 이 경우에는 충분히 visited 에 나중에 들어가는 값이 더 작게 들어갈 수 있습니다.

// 예를 들어 일반적인 Dijkstra 알고리즘에서도
// 정점이 3개이고 간선이 1에서 2 비용 5, 1에서 3 비용 10, 2에서 3 비용 3 이라 하고 시작점이 1번이라면
// visited[3] 에 처음에 10이 들어갔다가 실제로 3을 방문하기 전에 다시 8로 고쳐질 것입니다.

// 사실 그 외에도 좀 더 고려해야 하는 부분이 있습니다.
// (예컨대 어떤 정점을 K 번째 방문했다고 할 때 그 경로상에 있는 다른 정점들은 절대로 K 번보다 더 많이 방문해 있을 수 없다.. 라든지..)
// 참고로 위의 코드는 이러한 고려사항이 다 반영된 코드입니다.