from collections import deque

def is_valid(y: int, x: int, n: int, m: int):
    return 0 <= y < n and 0 <= x < m

def solution(maps): 
    answer = []
    # n 세로 * m 가로
    m = len(maps[0])
    n = len(maps)

    visited = [[False] * m for _ in range(n)]
    direct = [(0, 1), (0, -1), (1, 0), (-1, 0)] 
    
    def bfs(y, x):
        q = deque()
        q.append((y, x))
        visited[y][x] = True 
        cnt = 0
        
        while q:
            cy, cx = q.popleft()
            cnt += int(maps[cy][cx])
            
            for dy, dx in direct:
                ny = cy + dy
                nx = cx + dx
                    
                if is_valid(ny, nx, n, m) and maps[ny][nx] != 'X' and not visited[ny][nx]:          
                    q.append((ny, nx))
                    visited[ny][nx] = True 
        
        return cnt 
    
    
    for y in range(n):
        for x in range(m):
            if maps[y][x] != 'X' and not visited[y][x]:
                answer.append(bfs(y, x))
    
    if answer:
        answer.sort()
    else:
        answer.append(-1)
    
    return answer