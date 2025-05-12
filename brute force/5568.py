from itertools import permutations

n = int(input())
k = int(input())

nums = list(input() for _ in range(n))
ans = set()

for p in permutations(nums, k):
    ans.add(''.join(p))

print(len(ans))