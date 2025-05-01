N = int(input())
nums = list(map(int, input().split()))

nums.sort()

j = len(nums) - 1
minSum = 10 ** 10
ans = ()

for i in range(len(nums)):
    while j > i:       
        newSum = nums[i] + nums[j]

        if abs(newSum) < minSum: #새로운 합이 더 0에 가까운 경우
            minSum = abs(newSum)
            ans = (nums[i], nums[j])

        if newSum < 0: #i 증가
            break

        else: #j 감소
            j -= 1

print(*ans)