def solution(s):
    n = len(s)
    if n % 2 == 0:
        answer = s[int(n/2-1)]+s[int(n/2)]
    else:
        answer = s[int(n/2)]
    return answer