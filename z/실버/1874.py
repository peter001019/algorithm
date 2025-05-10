def check(list, n, resultList):
    i = 0
    stack = [0]

    for num in list:
        while(True):
            if(stack[-1] == num):
                stack.pop()
                resultList.append('-')
                break
            else:
                if(i > n):
                    resultList.clear()
                    return
                i += 1
                stack.append(i)
                resultList.append('+')

n = int(input())

list = []
for _ in range(n):
    list.append(int(input()))

resultList = []
check(list, n, resultList)

if(len(resultList) == 0):
    print("NO")
else:
    for c in resultList:
        print(c)


