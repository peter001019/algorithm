N, S = map(int, input().split())
nums = list(map(int, input().split()))

start, end = 0, 0
sum = nums[0]
min_len = len(nums) + 1

while True:
    if sum < S:
        end += 1
        if end == N:
            break
        sum += nums[end]

    else:
        min_len = min(min_len, end - start + 1)
        sum -= nums[start]
        start += 1

print(min_len if min_len <= len(nums) else 0)

'''
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
'''