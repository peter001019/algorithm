import heapq

N = int(input())
time = [list(map(int, input().split())) for _ in range(N)]

time.sort(key=lambda t: (t[0], t[1]))

hq = [time[0][1]]

for i in range(1, len(time)):
    if hq[0] <= time[i][0]:
        heapq.heappop(hq)
    heapq.heappush(hq, time[i][1])

print(len(hq))