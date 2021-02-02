import heapq
import sys

heap = []
res = []

n = int(input())

for i in range(n):
    x = int(sys.stdin.readline())

    if x:
        heapq.heappush(heap, x)
    elif(heap):
        res.append(heap[0])
        heapq.heappop(heap)
    else:
        res.append(0)

print('\n'.join(map(str, res)))
