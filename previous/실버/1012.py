import sys
sys.setrecursionlimit(10**5)
def dfs(a, b):
    if(a < 0 or b < 0 or a >= len(matrix) or b >= len(matrix[0])):
        return False
    if(matrix[a][b] == 1):
        matrix[a][b] = 0 # 방문 처리
        dfs(a - 1, b)
        dfs(a, b - 1)
        dfs(a + 1, b)
        dfs(a, b + 1)
        return True
    return False

T = int(sys.stdin.readline()) 
results = []

for _ in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    matrix = [[0 for _ in range(M)] for _ in range(N)]

    result =  0
    for _ in range(K):
        b, a = map(int, sys.stdin.readline().split()) # 좌표 a, b
        matrix[a][b] = 1

    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 1:
                dfs(i, j)
                result += 1
    
    results.append(result)

for result in results:
    print(result)