def solution(numbers):
    
    li = list(range(0, 10))
    
    for n in numbers:
        li.remove(n)
        
    answer = sum(li) 
    return answer