from queue import PriorityQueue

def check(mid, q):
    num = 0
    for n in q.queue:        
        num += n // mid
        if(N <= num):
            return True
    return False

K, N = map(int, input().split())
q = PriorityQueue()

for _ in range(K):
    q.put(int(input()))

start = 1
end = q.queue[K - 1]
mid = 0

while(start <= end):
    mid = (start + end) // 2

    if(check(mid, q)):
        start = mid + 1

    else:
        end = mid - 1

print(end)