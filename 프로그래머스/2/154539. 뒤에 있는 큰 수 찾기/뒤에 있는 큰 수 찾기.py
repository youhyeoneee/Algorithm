def solution(numbers):
    n = len(numbers)
    answer = [-1] * n
    stack = []
    
    for idx in range(n):
        while len(stack) > 0 and numbers[idx] > numbers[stack[-1]]:
            answer[stack[-1]] = numbers[idx]
            stack.pop()
        stack.append(idx)
    
    return answer