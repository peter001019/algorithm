import heapq, sys

N = int(input())
M = int(input())
INF = sys.maxsize

graph = [[] for _ in range(N + 1)]
distance = [int(INF) for _ in range(N + 1)]

for _ in range(M):
    start, end, cost = map(int, input().split())
    graph[start].append((cost, end))

start, end = map(int, input().split())

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, node = heapq.heappop(q)

        if dist > distance[node]:
            continue
        
        for weight, neighbor in graph[node]:
            cost = dist + weight

            if cost < distance[neighbor]:
                distance[neighbor] = cost
                heapq.heappush(q, (cost, neighbor))

dijkstra(start)

print(distance[end])