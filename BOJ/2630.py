white = 0
blue = 0
def cut(left, top, length):
    global white
    global blue
    s = 0
    cnt = 0
    for r in range(top, top+length):
        for c in range(left, left+length):
            cnt += 1
            s += arr[r][c]
            if s != 0 and s != cnt:
                length //= 2
                cut(left, top, length)
                cut(left+length, top, length)
                cut(left, top+length, length)
                cut(left+length, top+length, length)
                return
    if s == 0:
        white += 1
    elif s == cnt:
        blue += 1

n = int(input())

arr = []
for i in range(n):
    arr.append(list(map(int, input().split(' '))))

cut(0, 0, n)
print(white)
print(blue)
