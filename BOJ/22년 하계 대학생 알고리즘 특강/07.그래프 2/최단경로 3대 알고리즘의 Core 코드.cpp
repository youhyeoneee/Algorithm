// [[[ 데이크스트라 알고리즘 ]]]
// 단일 시작점 -- 단일/다수 도착점, 혹은 단일/다수 시작점 -- 단일 도착점 경우 지원
// cost 가 음수인 간선이 하나도 없어야 함.
// 정점의 개수가 10만개대 규모이어도 커버 가능 (단 희소그래프여야....)

struct e_t {
  int node;
  int cost;
  e_t(int _node, int _cost) : node(_node), cost(_cost) {}
  bool operator<(const e_t &ref) const {
    return this->cost > ref.cost; // min heap 으로 동작
  }
};
std::vector<e_t> AL[20001];

// in main
std::priority_queue<e_t> PQ;  // cost 에 대한 min heap 형태로 동작해야 하므로

for (int i = 1; i <= V; i++) Visited[i] = INF;
Visited[Start] = 0;
PQ.push(e_t(Start, 0));

while (!PQ.empty()) {
  e_t curr = PQ.top();
  PQ.pop();
  for (e_t next : AL[curr.node]) {
    int cost = curr.cost + next.cost;
    if (cost < Visited[next.node]) {
      Visited[next.node] = cost;
      PQ.push(e_t(next.node, cost));
    }
  }
}


// [[[ 벨만포드무어 알고리즘 ]]]
// 단일 시작점 -- 단일/다수 도착점, 혹은 단일/다수 시작점 -- 단일 도착점 경우 지원
// 정점의 개수, 간선의 겨수의 규모가 수천개 수준 정도까지 커버 가능 (정확하게는 정점의 개수 X 간선의 개수 가 수백만 규모 정도이하)

struct e_t {
  int a, b, c;
} E[6001];

// in main
bool isNegativeCycle = false;

// N-1 만큼 돌리기
for (int i = 1; i < N; i++) {
  for (int j = 1; j <= M; j++) {
    if (Visited[E[j].a] < INT_MAX && Visited[E[j].a] + E[j].c < Visited[E[j].b]) {
      Visited[E[j].b] = Visited[E[j].a] + E[j].c;
    }
  }
}

// 음수 사이클 확인을 위해 한번 더 돌리기
for (int j = 1; j <= M; j++) {
  if (Visited[E[j].a] < INT_MAX && Visited[E[j].a] + E[j].c < Visited[E[j].b]) {
    isNegativeCycle = true;
    break;
  }
}

// [[[ 플로이드워셜 알고리즘 ]]]
// 단일/다수 시작점 -- 단일/다수 도착점 지원 (모든 경우 지원)
// 정점의 개수 규모가 at most 300 개 정도 이하 수준 정도까지 커버 가능.

for (int k = 1; k <= N; k++) { // k : 경유지
  for (int i = 1; i <= N; i++) { // i : 출발지
    for (int j = 1; j <= N; j++) { // j : 도착지
      if (AM[i][j] > AM[i][k] + AM[k][j]) {
        AM[i][j] = AM[i][k] + AM[k][j];
      }
    }
  }
}

// 방향성이 없는 간선으로 이루어진 그래프에서 최단경로를 구할 때에는
// 방향성이 없는 간선을 방향성이 있는 출발지 --> 도착지 간선과 도착지 --> 출발지 간선 두 개가 있는 것으로 간주하시면 됩니다.

// (만일 그렇다면 방향성이 없는 음수 간선이 존재하면 무조건 음수 사이클이 존재하겠죠..(!!!!!!). 이 부분도 한번 고찰해 보도록 합시다.)

