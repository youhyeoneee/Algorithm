    
def solution(info, edges):    
    visited = [False] * len(info)
    answer = []

    def dfs(sheep, wolf):
        if sheep > wolf:
            answer.append(sheep)
        else:
            return 
        
        for p, c in edges:
            if visited[p] and not visited[c]:
                visited[c] = True
                if info[c]:
                    dfs(sheep, wolf+1)
                else:
                    dfs(sheep+1, wolf)
                visited[c] = False
    
    # 루트 노드부터 시작
    visited[0] = True
    dfs(1, 0)
    
    return max(answer)