N, S = map(int, input().split())
nums = list(map(int, input().split()))

end = 0
sum = nums[0]
min_len = len(nums) + 1

for i in range(len(nums)):
    while end < N:
        if sum >= S:
            new_len = end - i + 1

            if new_len < min_len:
                min_len = new_len

            sum -= nums[i]
            break

        else:
            if end == N - 1: #end가 끝에 도달한 경우
                break

            end += 1  
            sum += nums[end]

print(min_len if min_len <= len(nums) else 0)