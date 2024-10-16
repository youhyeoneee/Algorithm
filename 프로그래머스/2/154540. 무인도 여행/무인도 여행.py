from collections import deque

def solution(maps): 
    answer = []
    
    # n 세로 * m 가로
    n = len(maps)
    m = len(maps[0])
    
    # 방문 체크 
    visited = [[False] * m for _ in range(n)]
    
    def bfs(y, x):
        q = deque()
        q.append((y, x))
        visited[y][x] = True 
        # 머물 수 있는 일수
        days = 0
        
        while q:
            cy, cx = q.popleft()
            days += int(maps[cy][cx])
            
            for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                ny, nx = cy + dy, cx + dx
                if 0 <= ny < n and 0 <= nx < m:
                    if maps[ny][nx] == 'X' or visited[ny][nx]:  
                        continue 
                    q.append((ny, nx))
                    visited[ny][nx] = True 
        
        return days 
    
    
    for y in range(n):
        for x in range(m):
            if maps[y][x] == 'X' or visited[y][x]:
                continue
            answer.append(bfs(y, x))
    
    if answer:
        answer.sort()
    else:
        answer.append(-1)
    
    return answer