from collections import deque

T =  int(input())
ans = []

def find_result(arr, p):
    reversed = False

    for func in p:
        if func == 'R':
            reversed = not reversed
        
        else:
            if not arr: #arr이 비어있는 경우
                ans.append("error")
                return

            else:
                arr.pop() if reversed else arr.popleft()

    if reversed:
        arr.reverse()
    
    ans.append("[" + ",".join(map(str, arr)) + "]")
     
for _ in range(T):
    p = input()
    n = int(input())
    line = input()
    arr = deque(map(int, line[1:-1].split(','))) if n > 0 else []

    find_result(arr, p)

for a in ans:
    print(a)