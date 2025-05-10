import math

M, N = map(int, input().split())

def prime(M, N):
    list = [True for _ in range(N + 1)]

    for i in range(2, int(math.sqrt(N)) + 1):
        if(list[i] == True):
            j = 2
            while(i * j <= N):
                list[i * j] = False
                j += 1

    if(M == 1): M += 1
    for i in range(M, len(list)):
        if list[i]:
            print(i)

prime(M, N)
