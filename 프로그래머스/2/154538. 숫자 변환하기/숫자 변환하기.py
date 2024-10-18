from collections import deque

def solution(x, y, n):
    
    if y == x:
        return 0
    
    answer = int(1e9)
    
    q = deque()
    q.append((y, 0))
    
    while q:
        num, cnt = q.popleft()

        if num == x:
            answer = min(answer, cnt)
        
        if num < x or cnt > answer:
            continue
        
        if num - n >= x:
            q.append((num - n, cnt + 1))
        
        if num % 3 == 0:
            q.append((num // 3, cnt + 1))

        if num % 2 == 0:
            q.append((num // 2, cnt + 1))
            
    if answer == int(1e9):
        return -1 
    
    return answer
