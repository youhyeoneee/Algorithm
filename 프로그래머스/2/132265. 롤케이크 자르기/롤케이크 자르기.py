from collections import Counter, defaultdict 

def solution(topping):
    answer = 0
    
    # 철수가 처음에 다 가지고 있을 때, 토핑 개수 세기 
    cheulsoo =  Counter(topping)
    
    # 동생 토핑 개수 
    brother = defaultdict(int)
    
    # 철수 토핑 개수
    cheulsoo_topping, brother_topping = len(cheulsoo), 0
    
    # 백만 
    while len(topping) > 1:
        t = topping.pop()
        
        # 철수 -> 동생에게 토핑 주기 
        cheulsoo[t] -= 1
        brother[t] += 1

        # 철수 map[토핑] = 0이면 철수 토핑 개수 -1 
        if cheulsoo[t] == 0:
            cheulsoo_topping -= 1
        
        # 동생 map[토핑]이면 동생 토핑 개수 +1 
        if brother[t] == 1:
            brother_topping += 1
            
        # 토핑 비교 
        if cheulsoo_topping == brother_topping:
            answer += 1
            
    return answer
        
    
    
    """ 1차 시도 : 시간초과 
    for i in range(len(topping)):
        cake_1 = len(set(topping[:i])) # 리스트 슬라이싱 O(N) ㅇ0ㅇ
        cake_2 = len(set(topping[i:]))
        
        if cake_1 == cake_2:
            answer += 1
        
    return answer
    """
