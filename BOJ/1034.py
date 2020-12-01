import itertools


def switch_col(c_list):
    res = 0
    for c in c_list:
        for i in range(len(rows)):
            rows[i][c] = not rows[i][c]
            res += all(rows[i])
            rows[i][c] = not rows[i][c]
    return res


n, m = input().split()
n = int(n)
m = int(m)
col_num = [i for i in range(m)]

rows = []
for i in range(n):
    rows.append([])
    temp = input()
    for j in range(m):
        rows[i].append(temp[j] == '1')

k = int(input())
hj = k % 2
if k > m:
    k = m

on_rows = []

for i in range(hj, k, 2):
    for cli in list(itertools.combinations(col_num, i)):
        on_rows.append(switch_col(cli))
print(max(on_rows))
