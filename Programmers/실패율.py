def solution(N, stages):
    answer = []
    reach = [0 for i in range(N+1)]
    clear = [0 for i in range(N)]
    
    for stage in stages:
        reach[stage-1] += 1
    for i in range(N, 0, -1):
        reach[i-1] += reach[i]
    
    for i in range(N):
        answer.append(
            (i+1, 
             1 if reach[i] == 0 
             else reach[i+1] / reach[i])
        )

    answer = sorted(answer, key=lambda x: x[1])    
    return [x[0] for x in answer]
