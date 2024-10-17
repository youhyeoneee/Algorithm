from collections import defaultdict


def solution(info, edges):
    graph = defaultdict(list)
    
    # 그래프 구성
    for parent, child in edges:
        graph[parent].append(child)
    
    # DFS 정의
    def dfs(node, sheep, wolf, possible_nodes):
        nonlocal answer
        if info[node] == 0:
            sheep += 1
        else:
            wolf += 1
        # print("=======")

        # print("node : ", node)
        # print("sheep : ", sheep, " wolf : ", wolf)
        # print(possible_nodes)
        # 늑대가 양을 넘으면 더 이상 탐색하지 않음
        if wolf >= sheep:
            return
        
        # 최대 양의 수 갱신
        answer = max(answer, sheep)
        
        # 이동 가능한 노드 복제 (다른 경로에 영향 안 미치도록)
        nodes = possible_nodes[:]
        nodes.remove(node)
        nodes.extend(graph[node])
        # print(nodes)

        # 다음 가능한 정점들로 이동
        for next_node in nodes:
            dfs(next_node, sheep, wolf, nodes)
    
    answer = 0
    dfs(0, 0, 0, [0])  # 시작은 0번 정점
    return answer
