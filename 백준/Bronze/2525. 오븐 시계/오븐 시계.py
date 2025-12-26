h,m = map(int, input().split())
t = int(input())

if (m+t) % 60 == 0: # 정각일 경우
    add_h = (m+t) // 60
    if (h+add_h) > 23:
        h = (h+add_h) % 24
    else: 
        h += add_h
    print(h, 0)
else:
    add_h = (m+t) // 60
    m = (m+t) % 60
    if (h+add_h) > 23:
        h = (h+add_h) % 24
    else:
        h += add_h
    print(h, m)

