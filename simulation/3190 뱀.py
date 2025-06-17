from collections import deque

N = int(input())
matrix = [[False] * (N + 1) for _ in range(N + 1)]

K = int(input())
for _ in range(K):
    y, x = map(int, input().split())
    matrix[y][x] = True

L = int(input())
info = {}
for _ in range(L):
    sec, direct = input().split()
    info[int(sec)] = direct

def in_range(x, y):
    return 1 <= x <= N and 1 <= y <= N

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

x, y = 1, 1 
direct = 0
time = 0
snake = deque([(x, y)])

while True:
    nx, ny = x + dx[direct], y + dy[direct]

    #벽에 부딪히는 경우 or 몸에 부딪히는 경우
    if not in_range(nx, ny) or (nx, ny) in snake:
        break

    time += 1

    if time in info.keys(): #방향 전환
        if info[time] == 'D':
            direct = (direct + 1) % 4
        else:
            direct = (direct + 3) % 4

    snake.append((nx, ny)) #이동

    if matrix[ny][nx]: #사과를 먹으면 사과는 없어짐
        matrix[ny][nx] = False
    
    else: #사과가 없으면 꼬리를 비워준다.
        snake.popleft()

    x, y = nx, ny

print(time + 1)