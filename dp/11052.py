N = int(input())
dp = [0] + list(map(int, input().split()))

for i in range(2, N + 1):
    for k in range(1, i // 2 + 1):
        dp[i] = max(dp[i], dp[i - k] + dp[k])

print(dp[N])

'''
1 * 4
2 * 2
211
1 + 3
4

1 2   3     4
1 1+1 1+1+1 1+1+1+1 -> dp[1] + dp[3]
  5   1+5   1+5+1*
      6     6+1* -> dp[2] + dp[2]
            5+5
            1+1+5

simulation? -> 재귀로 모든 경우의 수 파악, max 찾기

1. i개의 카드에서 금액의 최댓값
2. dp[i] = max(dp[i], dp[i - k] + dp[i]) //k = 1~i//2
3. P
'''