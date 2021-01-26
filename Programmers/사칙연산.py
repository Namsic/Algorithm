def calc_(nums, pm, m1, m2):
    if m2 == len(nums):
        m2 = m1 + 1
    return sum([nums[i] * pm[i] for i in range(m1)]) - sum(nums[m1:m2]) + sum(nums[m2:])

def solution(arr):
    answer = []
    nums = []
    pm = [1]
    for el in arr:
        if el == '+':
            pm.append(1)
        elif el == '-':
            pm.append(-1)
        else:
            nums.append(int(el))

    for i in range(len(nums)):
        if pm[i] == -1:
            j = i + 1
            while j < len(nums) and pm[j] != -1:
                j += 1
            answer.append(calc_(nums, pm, i, j))

    return max(answer) if len(answer) else sum(nums)
