T = int(input())
list = []

for i in range(T):
    a, b = map(int, input().split())
    list.append((a, b))

for (a, b) in list:
    num = 1
    b = b % 4
    if(b == 0): b = 4

    for i in range(b):
        num = (num * a) % 10

    if(num == 0): num = 10
    
    print(num)

