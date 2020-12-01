n = int(input().split()[0])

row_type = {}
for i in range(n):
    r = input()
    if r in row_type:
        row_type[r][0] += 1
    else:
        row_type[r] = [1, r.count('0')]  # [count, need]
k = int(input())

max_on = 0
for key in row_type:
    if row_type[key][1] > k:
        continue
    if row_type[key][1] % 2 != k % 2:
        continue
    if max_on < row_type[key][0]:
        max_on = row_type[key][0]
print(max_on)