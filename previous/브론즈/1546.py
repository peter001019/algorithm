N = int(input())
numList = list(map(int, input().split()))

M = max(numList)

sum = 0

for n in numList:
    n = n / M * 100   
    sum += n

print(sum / N)
