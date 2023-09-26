def solution(park, routes):
    
    w = len(park[0])
    h = len(park)
    
    nav = {
        'S' : [1, 0], # 남쪽
        'N' : [-1, 0], # 북쪽
        'W' : [0, -1], # 서쪽
        'E' : [0, 1]  # 동쪽
    }
    
    # 시작점 찾기
    for i in range(h):
        for j in range(w):
            if (park[i][j] == 'S'):
                y = i
                x = j
        
        
    for route in routes:
        op, n = route.split() # 방향, 이동할 칸의 수
        n = int(n)
        
        ny = y
        nx = x
        flag = True
        
        # n번 이동
        for i in range(n) :
            ny += nav[op][0]
            nx += nav[op][1]
            
            if (ny >= h or nx >= w or nx < 0 or ny < 0 or park[ny][nx] == 'X') :
                flag = False
                break
                    
        if (flag) : 
            y += nav[op][0] * n
            x += nav[op][1] * n
        
    answer = [y, x]
    return answer
    