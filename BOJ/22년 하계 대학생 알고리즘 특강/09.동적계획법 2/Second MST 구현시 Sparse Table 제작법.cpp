// 해당 경로의 간선 코스트 중 가장 큰 값과 두 번째로 큰 값을 저장해야 하므로 아래와 같이 구현해 봅시다.

struct path_t {
    int n, e1, e2; // e1 > e2
};

path_t Par[50001][16]; // Sparse Table, 정점 5만개, 2^15 스텝

// in function
// arr 은 그냥 temp 배열입니다.
// std::greater<int>() 펑터를 사용하려면 #include <functional> 을 넣으셔야 합니다.

for (int i = 1; i < 16; i++) {
    for (int v = 1; v <= V; v++) {
        Par[v][i].n = Par[Par[v][i - 1].n][i - 1].n;
        arr[0] = Par[v][i - 1].e1, arr[1] = Par[v][i - 1].e2;
        arr[2] = Par[Par[v][i - 1].n][i - 1].e1, arr[3] = Par[Par[v][i - 1].n][i - 1].e2;
        std::sort(arr, arr + 4, std::greater<int>());
        Par[v][i].e1 = arr[0];
        Par[v][i].e2 = arr[1] == arr[0] ? arr[2] : arr[1];
    }
}

// LCA 할 때에도 위와 비슷한 방법으로 간선의 코스트를 경합시켜야 합니다.
