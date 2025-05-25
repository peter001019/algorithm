import heapq

N, M = map(int, input().split())
times = list(map(int, input().split()))

times.sort(reverse=True)
socket = []

for t in times:
    if len(socket) < M:
        heapq.heappush(socket, t)
    else:
        heapq.heappush(socket, heapq.heappop(socket) + t)

print(socket[-1])