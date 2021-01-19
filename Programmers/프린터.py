def solution(priorities, location):
    answer = 0
    
    while True:
        p = priorities.pop(0)
        location -= 1
        if len(priorities) == 0 or p >= max(priorities):
            answer += 1
            if location < 0:
                return answer
        else:
            priorities.append(p)
            if location < 0:
                location = len(priorities)-1
