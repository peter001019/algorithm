n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]
dp = [0] * (k + 1)

coin.sort()
dp[0] = 1

for c in coin:
    for i in range(1, k + 1):
        if i >= c:
            dp[i] = dp[i] + dp[i - c]        

print(dp[k])
'''
1. i일 때 c번째 동전을 추가해서서 만들 수 있는 경우의 수
2. dp[i] = dp[i] + dp[i - coin]
  0 1 2  3   4    5      6 7 8 9 10
  0 1 11 111 1111 11111 
      2  12  11 2 1112
             2 2  122
                  5
3. 0
'''
