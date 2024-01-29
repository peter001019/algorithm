# N = int(input())
# num = N // 2
# isExist = False

# def check(num):
#     global N 
#     numList = [num]
#     sum = 0
    
#     while(num >= 1):
#         numList.append(num % 10)
#         num //= 10

#     for n in numList:
#         sum += n
    
#     if sum == N: return True
#     else: return False


# while(num < N):
#     if check(num):
#         isExist = True
#         break

#     num += 1

# if isExist: 
#     print(num)
# else:
#     print(0)


N = int(input())

for n in range(N // 2, N + 1):
    num = sum(map(int, str(n))) 
#map함수를 이용해 n을 문자열로 변환하고, 각 자리 수를 int로 iterate 할 수 있다.
    
    sumNum = n + num

    if sumNum == N:
        print(n)
        break

    if n == N:
        print(0)
        break