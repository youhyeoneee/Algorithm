from collections import deque, defaultdict

def solution(x, y, n):
    
    if y == x:
        return 0
    
    answer = int(1e9)
    visited = defaultdict(bool)
    
    q = deque()
    q.append((y, 0))
    
    while q:
        num, cnt = q.popleft()
        
        if num == x:
            answer = min(answer, cnt)
        
        if num < x or cnt > answer:
            continue
        
        if num - n >= x and not visited[num - n]:
            q.append((num - n, cnt + 1))
            visited[num - n] = True 
        
        if num % 3 == 0 and not visited[num // 3]:
            q.append((num // 3, cnt + 1))
            visited[num // 3] = True 

        if num % 2 == 0 and not visited[num // 2]:
            q.append((num // 2, cnt + 1))
            visited[num // 2] = True 
            
    if answer == int(1e9):
        return -1 
    
    return answer
