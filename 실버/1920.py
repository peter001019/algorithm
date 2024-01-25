N = int(input())
list = list(map(int, input().split()))
M = int(input())
n = list(map(int, input().split()))

list.sort()

def binarySearch(start, end, num):
    mid = (start + end) // 2

    if(start <= end):
        if(list[mid] > num):
            return binarySearch(start, mid - 1, num)
        elif(list[mid] < num):
            return binarySearch(mid + 1, end, num)
        else:
            print(1)
            return
    else:
        return print(0)

for num in n:
    if(num > list[-1] or num < list[0]):
        print(0)
    else:
        binarySearch(0, len(list) - 1, num)
    
