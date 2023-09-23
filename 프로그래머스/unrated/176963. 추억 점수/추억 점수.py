def solution(name, yearning, photo):
    answer = []
    
    # 이름 - 점수 딕셔너리
    dictionary = dict(zip(name, yearning))
    
    # 100 * 100 = 10000
    for p in photo: # p = 사진
        sum = 0;
        for n in p: # n = 이름
            try:    
                sum += dictionary[n] # 점수 더하기 
            except:
                pass
        answer.append(sum) # 총점 

    return answer