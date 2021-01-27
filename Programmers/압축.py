def solution(msg):
    LZWdict = {}
    idx = 1
    while idx < 27:
        LZWdict[chr(idx+64)] = idx
        idx += 1
    answer = []

    while True:
        if msg in LZWdict:
            answer.append(LZWdict[msg])
            break
        
        l = len(msg)-1
        while msg[:l] not in LZWdict:
            l -= 1
        answer.append(LZWdict[msg[:l]])
        LZWdict[msg[:l+1]] = idx
        idx += 1
        msg = msg[l:]
    return answer
