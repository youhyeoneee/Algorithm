def solution(numbers):
    answer = [-1 for i in range(len(numbers))]
    
    stack = []
    
    for idx, target in enumerate(numbers):
        while stack and target > numbers[stack[-1]]:
            answer[stack.pop()] = target
        
        stack.append(idx)
        
    return answer