def get_pos(num, pos):
    num = num // (10 ** pos)
    return num % 10

def set_pos(num, pos, v):
    pow10 = 10 ** pos

    tmp = num % pow10
    num = num // pow10
    num += v - (num % 10)
    num *= 10 ** pos
    return num + tmp


n = int(input())

i = 0
num = 0
pos = 0
while i < n:
    if num == 9876543210:
        break
    gp = get_pos(num, pos)
    if pos == len(str(num))-1:
        if gp == 9:
            for j in range(pos+2):
                num = set_pos(num, j, j)
            i += 1
            pos = 0
        else:
            num = set_pos(num, pos, gp+1)
            i += 1
            pos = 0
    elif gp < get_pos(num, pos+1)-1:
        num = set_pos(num, pos, gp+1)
        i += 1
        pos = 0
    elif gp == get_pos(num, pos+1)-1:
        num = set_pos(num, pos, pos)
        pos += 1

if i == n:
    print(num)
else:
    print(-1)
