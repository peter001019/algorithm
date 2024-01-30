from collections import deque

N = int(input())
deque = deque([n for n in range(1, N + 1)])

while(len(deque) > 1):
    deque.popleft()
    deque.append(deque.popleft())

print(deque.pop())



