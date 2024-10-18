def find_max_sum(arr):
    max_value = max(arr)
    max_value_index = arr.index(max_value)
    min_value = 0
    if max_value_index:
        min_value = min(arr[:max_value_index])    
    return max_value - min_value

def set_presum(arr):
    presum = [0]
    
    for i in range(1, len(arr)+1):
        presum.append(presum[i-1] + arr[i-1])
    return presum

def solution(sequence):
    answer = 0
    n = len(sequence)
    
    # 2가지 펄스 배열 곱하기 
    perse_1, perse_2 = [], [] 
    
    num = 1 
    for i in range(n):
        perse_1.append(num * sequence[i])
        perse_2.append(-num * sequence[i])
        num *= -1
    
    # 누적합 
    presum_1, presum_2 = set_presum(perse_1), set_presum(perse_2)
    
    # 가장 큰 부분 수열의 합 구하기 
    answer = max(answer, find_max_sum(presum_1), find_max_sum(presum_2))
    return answer