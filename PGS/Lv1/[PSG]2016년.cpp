def solution(a, b):
    month = [31 ,29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    co_day = 0
    i = 0
    c = ["THU", "FRI", "SAT", "SUN" , "MON", "TUE", "WED"]
    while i < a -1 :
        co_day += month[i]
        i += 1
    co_day = co_day + b
    answer = c[co_day % 7 ]
    return answer