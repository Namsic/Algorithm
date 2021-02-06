def solution(s):
    stack = []
    for c in s:
        stack.pop() if len(stack) and stack[-1] == c else stack.append(c)
    return int(not len(stack))
