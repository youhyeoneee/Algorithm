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

    presum_1, presum_2 = [0], [0]
    
    for i in range(1, n+1):
        presum_1.append(presum_1[i-1] + perse_1[i-1])
        presum_2.append(presum_2[i-1] + perse_2[i-1])

    # 누적합 max

    max_value = max(presum_1)
    max_value_index = presum_1.index(max_value)
    # print(max_value_index)
    min_value = 0
    if max_value_index:
        min_value = min(presum_1[:max_value_index])
    answer = max(max_value - min_value, answer)
    
     # 누적합 max
    # print(presum_2)
    max_value = max(presum_2)
    max_value_index = presum_2.index(max_value)
    min_value = 0
    if max_value_index:
        min_value = min(presum_2[:max_value_index])
    # print(max_value, min_value)

    answer = max(max_value - min_value, answer)   
    
    return answer