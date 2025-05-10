N = int(input())

# 1. 소수 구하기 - 에라토스테네스의 체
nums = [i for i in range(N + 1)]
nums[1] = 0

for i in range(2, int(len(nums) ** (1/2)) + 1):
    if nums[i] == 0:
        continue
    for j in range(i*i, N + 1, i):
        nums[j] = 0

prime = []

for n in nums:
    if n != 0:
        prime.append(n)

# 2. 합 구하기
start = 0
end = 0
ans = 0
if N != 1: sum = prime[start]

while N != 1:
    if sum <= N:
        if sum == N:
            ans += 1

        if end == len(prime) - 1:
            break

        end += 1
        sum += prime[end]
    
    else:
        sum -= prime[start]
        start += 1

print(ans)

'''
1. 소수가 뭔질 알아야 함.

2. 소수를 순회하며 덧셈할 수 있는지 검사.

3. 모든 경우를 구한다.
'''