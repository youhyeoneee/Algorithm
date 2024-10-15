from collections import defaultdict

def solution(k, tangerine):
    
    count_dict = defaultdict(int)    
    for t in tangerine:
        count_dict[t] += 1
    
    counts = list(count_dict.values())
    counts.sort(reverse=True)
    
    answer = 0
    for count in counts:
        k -= count
        answer += 1

        if k <= 0:
            break
    
    return answer