import heapq

N = int(input())
times = [list(map(int, input().split())) for _ in range(N)]

times.sort(key=lambda t: (t[1], t[2]))

heap = [times[0][2]]

for i in range(1, len(times)):
    if heap[0] <= times[i][1]:
        heapq.heappop(heap)
    heapq.heappush(heap, times[i][2])

print(len(heap))