N = int(input())
parent = list(map(int, input().split()))
rmNode = int(input())

tree = [[] for _ in range(N)]
root = -1

for i in range(len(parent)):
    if parent[i] == -1:
        root = i
        continue
    tree[parent[i]].append(i)

#노드 제거
if parent[rmNode] != -1:
    tree[parent[rmNode]].remove(rmNode)

# dfs 탐색
stack = []
visited = [False] * N
ans = 0

# dfs 탐색
def dfs(k):
    global ans

    stack.append(k)
    visited[k] = True

    while stack:
        n = stack.pop()

        if not tree[n]: # 리프 노드
            ans += 1
            continue

        for t in tree[n]:
            if not visited[t]:
                stack.append(t)
                visited[t] = True

if parent[rmNode] != -1:
    dfs(root)

print(ans)