N, M = map(int, input().split())
nums = list(map(int, input().split()))

stations = []

ans = []

def make(where, i, j):
    for k in range(len(nums)):
        if nums[k] == i:
            if where == 'N':
                ans.append(nums[(k + 1) % len(nums)])
                nums.insert((k + 1) % len(nums), j)
            else:
                ans.append(nums[(k - 1)])
                nums.insert(k, j)
            return

def delete(where, i):
    for k in range(len(nums)):
        if nums[k] == i:
            if where == 'N':
                ans.append(nums[(k + 1) % len(nums)])
                nums.pop((k + 1) % len(nums))
            else:
                ans.append(nums[(k - 1)])
                nums.pop(k - 1)
            return

for _ in range(M):
    cons = input().split()

    if len(cons) == 3:
        make(cons[0][1], int(cons[1]), int(cons[2]))
    else:
        delete(cons[0][1], int(cons[1]))

for a in ans:
    print(a)