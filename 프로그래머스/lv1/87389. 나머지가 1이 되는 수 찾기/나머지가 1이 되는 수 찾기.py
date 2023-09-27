def solution(n):
    answer = 0
    
    while(True):
        answer += 1
        if (n%answer == 1) :
            break
    
    return answer