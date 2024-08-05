def choose(sum):
    global count

    if sum == n:
        count += 1
        #print(*arr)
        return 
    
    for i in range(1, 4):
        if sum + i > n:
            break
        
        arr.append(i)
        choose(sum + i)
        arr.pop()

T = int(input())
result = []
arr = []

for _ in range(T):
    n = int(input())

    count = 0
    choose(0)
    result.append(count)

for n in result: 
    print(n)
    
'''
1. 브루트포스 -> choose
- i번째 일때 가능한 수

2. 규칙찾기 -> 실패
dp[1] = 1 -> 1
dp[2] = 1 1, 2 -> 2 dp[1] + 본인
dp[3] = 1 1 1, 1 2, 2 1, 3 -> 4 dp[1], dp[2] + 본인
dp[4] = 1 1 1 1, 1 1 2, 1 2 1, 2 1 1, 2 2, 1 3, 3 1 -> 7 dp[1] dp[3] 
dp[5] = dp[2] + dp[3] -> 13
        11111, 1112, 1121, 113, 2111, 212, 221, 23
             , ,, 311, 32
             , 1211, 131, 122, 
'''