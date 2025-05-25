import sys

N, M = map(int, input().split())
t = list(map(int, input().split()))

t.sort()
socket = [0] * M
ans = 0

while True:
    min_time = sys.maxsize

    for i in range(len(socket)): #콘센트에 추가
        if socket[i] == 0 and t:
            socket[i] = t.pop()

        if socket[i] != 0 and min_time > socket[i]: #가장 작은 시간 찾기
            min_time = socket[i]

    isOver = True

    for i in range(len(socket)):
        if socket[i] != 0:
            isOver = False

    if isOver:
        break

    ans += min_time

    for i in range(len(socket)): #시간이 지나감
        if socket[i] != 0:
            socket[i] -= min_time

print(ans)