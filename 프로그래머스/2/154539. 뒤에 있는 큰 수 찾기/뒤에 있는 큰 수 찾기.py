def solution(numbers):
    n = len(numbers)
    answer = [-1] * n
    stack = []
    
    for idx in range(n):
        target = numbers[idx]
        while stack and target > numbers[stack[-1]]:
            answer[stack.pop()] = target
            
        stack.append(idx)
    
    return answer