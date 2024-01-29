import math

N = int(input())
aver = 0
mid = 0
most = 0
width = 0
index = 0
min = math.inf
max = -math.inf
most_list = []

numbers = [0 for _ in range(4001)]
minus_numbers = [0 for _ in range(4001)]

def find_mid(i, num):
    global N
    global index
    global mid

    index += num
    if index >= N // 2 + 1:
        mid = i

def find_most(i, num):
    global most
    global most_list

    if most < num:
        most = num
        most_list.clear()
        most_list = [i]
    
    elif most == num:
        most_list.append(i)

def find_width(i):
    global min
    global max

    if i < min:
        min = i
    if i > max:
        max = i

for _ in range(N):
    num = int(input())

    aver += num

    if num >= 0: #hashing
        numbers[num] += 1
    else:
        minus_numbers[-num] += 1

for i in range(len(minus_numbers)):
    if minus_numbers[i] != 0:
        if index < N // 2 + 1: find_mid(-i, minus_numbers[i]) #중앙값 찾기
        find_width(-i)
        find_most(-i, minus_numbers[i])

for i in range(len(numbers)):
    if numbers[i] != 0:
        if index < N // 2 + 1: find_mid(i, numbers[i]) #중앙값 찾기
        find_width(i)
        find_most(i, numbers[i])

width = max - min
print(math.ceil(aver / N))
print(mid)

most_list.sort()
if len(most_list) > 1:
    print(most_list[1])
else: 
    print(most_list[0])
print(width)
