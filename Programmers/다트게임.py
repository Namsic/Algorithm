def solution(dartResult):
    bonus = {'S': 1, 'D': 2, 'T': 3}
    answer = [0]
    tmp = ''
    
    for c in dartResult:
        if c.isdigit():
            tmp += c
        elif c in bonus:
            answer.append(int(tmp))
            answer[-1] **= bonus[c]
            tmp = ''
        elif c == '*':
            answer[-1] *= 2
            answer[-2] *= 2
        elif c == '#':
            answer[-1] *= -1
    
    return sum(answer)
