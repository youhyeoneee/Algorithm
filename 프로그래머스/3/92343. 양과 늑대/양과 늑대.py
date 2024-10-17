def solution(info, edges):
    from collections import defaultdict
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
        
        # 늑대가 양을 넘으면 더 이상 탐색하지 않음
        if wolf >= sheep:
            return
        
        # 최대 양의 수 갱신
        answer = max(answer, sheep)
        
        # 이동 가능한 노드 복제 (다른 경로에 영향 안 미치도록)
        possible_nodes = possible_nodes[:]
        possible_nodes.remove(node)
        possible_nodes.extend(graph[node])
        
        # 다음 가능한 정점들로 이동
        for next_node in possible_nodes:
            dfs(next_node, sheep, wolf, possible_nodes)
    
    answer = 0
    dfs(0, 0, 0, [0])  # 시작은 0번 정점
    return answer
