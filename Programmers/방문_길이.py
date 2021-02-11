def solution(dirs):
    vertical = set()
    horizontal = set()
    x, y = 0, 0
    for d in dirs:
        if d == 'U' and y < 5:
            y += 1
            vertical.add((x, y-1))
        elif d == 'D' and y > -5:
            y -= 1
            vertical.add((x, y))
        elif d == 'L' and x > -5:
            x -= 1
            horizontal.add((x, y))
        elif d == 'R' and x < 5:
            x += 1
            horizontal.add((x-1, y))
    return len(vertical) + len(horizontal)
