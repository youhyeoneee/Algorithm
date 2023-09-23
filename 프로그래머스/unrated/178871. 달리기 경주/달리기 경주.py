def solution(players, callings):
    answer = []
    
    playerDict = {};
    
    # players[i]
    
    for i in range(len(players)):
        playerDict[players[i]] = i;
        
    for call in callings:
        i = playerDict[call] # 현재 플레이어 순위
        playerDict[call] -= 1 # 추월함
        playerDict[players[i-1]] += 1 # 추월당함
        players[i], players[i-1] = players[i-1], players[i] # swap

        
    answer = players
    return answer