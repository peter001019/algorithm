import sys

N = int(input())
price = [list(map(int, input().split())) for _ in range(N)]
dp = [[sys.maxsize] * 3 for _ in range(N)]

for i in range(3):
    dp[0][i] = price[0][i]

for i in range(1, N):
    for j in range(3):
        for k in range(3):
            if(j != k):
                dp[i][j] = min(dp[i][j], price[i][j] + dp[i - 1][k])

print(min(dp[N - 1]))