def can_on(bulb):
    res = [True for i in range(10)]
    num_str = [
        '####.##.##.####',  # 0
        '..#..#..#..#..#',  # 1
        '###..#####..###',  # 2
        '###..####..####',  # 3
        '#.##.####..#..#',  # 4
        '####..###..####',  # 5
        '####..####.####',  # 6
        '###..#..#..#..#',  # 7
        '####.#####.####',  # 8
        '####.####..####',  # 9
        ]
    
    for i in range(15):
        for n in range(10):
            if bulb[i] == '#' and num_str[n][i] == '.':
                res[n] = False

    if not any(res):
        return -1

    li = []
    for i in range(10):
        if res[i]:
            li.append(i)
    return sum(li) / len(li)


n = int(input())
input_data = []
for line in range(5):
    input_data.append(input())

bulb = []
for i in range(n):
    bulb.append('')
    for j in range(5):
        bulb[i] += input_data[j][i*4:i*4+3]

res = 0
for i in range(n):
    c = can_on(bulb[i])
    if c == -1:
        res = -1
        break
    res *= 10
    res += c
print(res)
