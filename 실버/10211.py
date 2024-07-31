import sys

INT_MIN = -sys.maxsize - 1

def find_maxarray():
    for i in range(1, N):
        dp[i] = max(dp[i - 1] + a[i], a[i])
    result.append(max(dp))

result = []
T = int(input())

for _ in range(T):
    N = int(input())
    a = list(map(int, input().split()))
    dp = [a[0]] + [INT_MIN] * (N - 1)
    find_maxarray()
    
for n in result:
    print(n)

'''
1. i번째 위치일 때, 최대 합.
2. dp[i] = max(dp[i - 1] + a[i], a[i])
3. INT_MIN
'''