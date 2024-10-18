
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
def solution(x, y, n):
    answer = 0
    s = set()
    s.add(x)

    while s:
        if y in s:
            return answer

        nxt = set()
        for i in s:
            if i+n <= y:
                nxt.add(i+n)
            if i*2 <= y:
                nxt.add(i*2)
            if i*3 <= y:
                nxt.add(i*3)
        s = nxt
        answer+=1

    return -1
