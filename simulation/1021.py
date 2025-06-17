from collections import deque 

N, M = map(int, input().split())
idx = list(map(int, input().split()))

dq = deque([(i + 1) for i in range(N)])
cnt = 0

for i in idx:
    # 1. 위치 탐색
    for k in range(len(dq)):
        if dq[k] == i:
            break
    
    # 2. 연산 및 제거
    if k <= len(dq) / 2: #left 연산
        while dq[0] != i:
            dq.append(dq.popleft())
            cnt += 1
        dq.popleft()
    
    else:
        while dq[0] != i:
            dq.appendleft(dq.pop())
            cnt += 1
        dq.popleft()

print(cnt)