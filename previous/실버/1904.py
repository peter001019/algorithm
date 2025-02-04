def cnt():
    if N == 1:
        return 1
    elif N == 2:
        return 2
    else:
        dp[0], dp[1] = 1, 2

        for _ in range(2, N):
            dp.append((dp[1] + dp[0]) % 15746)
            dp.pop(0)

        return dp[1]

N = int(input())
dp = [0] * (2)

print(cnt())

'''
1. i번째는 i - 2와 i - 1번째의 개수를 더한 것.
2. dp[i] = dp[i - 2] + dp[i - 1]
3. dp[1] = 1, dp[2] = 2, 나머지는 0
'''