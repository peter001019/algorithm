max_int = 1e9

N = int(input())
nums = list(map(int, input().split()))

dp_max = nums[:] #최댓값 찾기
dp_min = nums[:] #최솟값

for _ in range(N - 1):
    nums = list(map(int, input().split()))
    curr_max = [-1] * 3
    curr_min = [max_int] * 3
    
    for j in range(3):
        for k in range(3):
            if abs(j - k) <= 1: #별과 다음 위치가 한 칸 이상 차이 나는 경우 제외
                curr_max[j] = max(curr_max[j], nums[j] + dp_max[k])
                curr_min[j] = min(curr_min[j], nums[j] + dp_min[k])
            
    dp_max, dp_min = curr_max, curr_min

print(max(dp_max), min(dp_min))

'''
1. i번째 행의 j번째 원소를 선택했을 때 최댓값, 최솟값
2. dp[i][j] = max or min (dp[])
3. min or max
'''
