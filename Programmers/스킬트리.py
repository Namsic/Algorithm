def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        idx = 0
        can = True
        for sk in skill_tree:
            if sk in skill:
                if sk == skill[idx]:
                    idx += 1
                else:
                    can = False
                    break
        if can:
            answer += 1
    return answer
