import sys

n = int(input())
k = int(input())

nums = list(input() for _ in range(n))
ans = set()

visited = [False] * len(nums)

def add(path):
    num = ""

    for a in path:
        num += a
    
    ans.add(num)

def permutation(path):
    if len(path) == k:  
        add(path)
        return
    
    for i in range(len(nums)):
        if visited[i]:
            continue

        path.append(nums[i])
        visited[i] = True
        permutation(path)
        path.pop()
        visited[i] = False

permutation([])

print(len(ans))