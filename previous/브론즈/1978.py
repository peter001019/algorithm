import math

def is_prime(num):
    if num == 1:
        return False

    for n in range(2, int(math.sqrt(num)) + 1):
        if num % n == 0:
            return False
    return True


N = int(input())

list = list(map(int, input().split()))
result = 0

for n in list:
    if is_prime(n):
        result += 1

print(result)
