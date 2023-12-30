def fibonacci(n): #상향식 동적 프로그래밍
    if(n == 0): 
        return (1, 0)
    elif(n == 1):
        return (0, 1)
    elif(n >= 2):
        f = [(0, 0)] * (n + 1)
        f[0] = (1, 0)
        f[1] = (0, 1)
        for i in range(2, n + 1):
            f[i] = (f[i - 1][0] + f[i - 2][0], f[i - 1][1] + f[i - 2][1])
        return (f[n][0], f[n][1])

T = int(input())
list = []

for i in range(T):
    N = int(input())
    list.append(fibonacci(N))

for (zero, one) in list:
    print(f'{zero} {one}')

