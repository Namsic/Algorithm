def solution(words):
    words.sort()
    answer = 0
    for i in range(len(words)-1, -1, -1):
        minType = 1
        while i > 0 and words[i][:minType] == words[i-1][:minType] and minType < len(words[i]):
            minType += 1
        while i < len(words)-1 and words[i][:minType] == words[i+1][:minType] and minType < len(words[i]):
            minType += 1
        answer += minType
    return answer
