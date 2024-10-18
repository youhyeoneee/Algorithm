def solution(sequence):
    v = [0]
    for i,s in enumerate(sequence): v.append(v[-1] + s * [1,-1][i%2])
    return max(v) - min(v)