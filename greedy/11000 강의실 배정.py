import heapq

N = int(input())
classes = [list(map(int, input().split())) for _ in range(N)]

classes.sort(key=lambda c: (c[0], c[1]))

hq = [classes[0][1]]

for i in range(1, len(classes)):
    if hq[0] <= classes[i][0]:
        heapq.heappop(hq)

    heapq.heappush(hq, classes[i][1])

print(len(hq))