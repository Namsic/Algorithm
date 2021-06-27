# 5430 - AC

t = int(input())

for tt in range(t):
    p = input().replace('RR','')
    n = int(input())
    x = eval(input())

    l = 0
    r = n
    rvs = False
    err = False
    for c in p:
        if c == 'R':
            rvs = not rvs
            continue
        if rvs:
            r -= 1
        else:
            l += 1
        if l > r:
            err = True
            break
    if err:
        print('error')
    else:
        answer = x[l:r]
        if rvs:
            answer.reverse()
        print(str(answer).replace(' ',''))
