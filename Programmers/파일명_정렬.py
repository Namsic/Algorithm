def solution(files):
    answer = []
    for filename in files:
        for i in range(len(filename)):
            if filename[i].isdigit():
                left = i
                right = i + 1
                while right < len(filename) and filename[right].isdigit():
                    right += 1
                answer.append((
                    filename[:left], 
                    filename[left:right],
                    filename[right:] if right < len(filename) else ''
                ))
                break
    
    answer.sort(key=lambda x : (x[0].lower(), int(x[1])))
    return [''.join(x) for x in answer]
