n = int(input())
a = [0]
dp = [0] * (n + 1)
for _ in range(n):
    a.append(int(input()))
dp[1] = a[1]

if n >= 2:
    dp[2] = a[1] + a[2]

for i in range(3, n + 1):
        dp[i] = a[i] + max(dp[i - 2], dp[i - 3] + a[i - 1])

print(dp[n])