from collections import deque 

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def in_range(x, y):
    return 0 < x <= N and 0 < y <= N

N = int(input())

matrix = [[0] * (N + 1)] 
for _ in range(N):
    row = [0] + list(map(int, input().strip()))
    matrix.append(row)

visited = [[False] * (N + 1) for _ in range(N + 1)]
q = deque()
house = []
count = 0

def bfs(x , y):
    q.append((x, y))
    visited[y][x] = True
    count = 0

    while q:
        x, y = q.popleft()
        count += 1

        for dxs, dys in zip(dx, dy):
            nx = x + dxs
            ny = y + dys

            if in_range(nx, ny) and not visited[ny][nx] and matrix[ny][nx] == 1:
                q.append((nx, ny))
                visited[ny][nx] = True
    house.append(count)

for y in range(1, N + 1):
    for x in range(1, N + 1):
        if matrix[y][x] and not visited[y][x]:
            bfs(x ,y)
            count += 1 #단지 세기

print(count)
house.sort()
for h in house:
    print(h)