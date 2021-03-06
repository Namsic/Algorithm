# 1043 - 거짓말

m = int(input().split(' ')[1])
enemy = set(input().split(' ')[1:])
parties = []
for i in range(m):
    parties.append(set(input().split(' ')[1:]))

posible_lie = [True for i in range(m)]

repeat = True
while repeat:
    repeat = False
    for i in range(len(parties)):
        if not posible_lie[i]:
            continue
        if len(enemy | parties[i]) < len(enemy) + len(parties[i]):
            posible_lie[i] = False
            enemy |= parties[i]
            repeat = True

print(sum(posible_lie))
