from collections import Counter

def solution(k, tangerine):
        
    counts = Counter(tangerine).most_common(k)
    answer = 0
    for size, count in counts:
        k -= count
        answer += 1

        if k <= 0:
            break
    
    return answer