import sys

def solution(N: int, K: int, items: list):
    # 초기화
    dp = [[0] * (K+1) for _ in range(N+1)]

    for idx, (w, v) in enumerate(items):
        i = idx+1
        for j in range(1, K+1):
            # 현재 물건을 배낭에 담을 수 없는 경우
            if w > j:
                dp[i][j] = dp[i-1][j]
            # 현재 물건을 배낭에 담을 수 있는 경우 
            else:
                # 현재 물건을 담았을 경우 vs 담지 않았을 경우
                dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j])
    return dp[N][K]

N, K = map(int, sys.stdin.readline().split())
items = [list(map(int,  sys.stdin.readline().split())) for _ in range(N)]
print(solution(N, K, items))
