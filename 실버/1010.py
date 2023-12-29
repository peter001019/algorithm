
def factorial(n):
    if(n <= 1): return 1
    else:
        return n * factorial(n - 1)

T = int(input())
list = []

for i in range(T):
    N, M = map(int, input().split())
    result = factorial(M) // ( factorial(M - N) * factorial(N) )
    list.append(result)

for i in range(T):
    print(list[i])



