N = int(input())
list = [int(input()) for _ in range(N)]

def merge(left, mid, right, list):
    sortedList = []
    leftPtr = left
    rightPtr = mid + 1
    while(leftPtr <= mid and rightPtr <= right):
        if list[leftPtr] < list[rightPtr]: 
            sortedList.append(list[leftPtr])
            leftPtr += 1
        else: 
            sortedList.append(list[rightPtr])
            rightPtr += 1
    
    if leftPtr <= mid : 
        for i in range(leftPtr, mid + 1): sortedList.append(list[i])
    else: 
        for i in range(rightPtr, right + 1): sortedList.append(list[i])
    
    for i in range(left, right + 1): list[i] = sortedList[i - left]

def mergeSort(left, right, list):
    if left < right: #원소가 2개 이상일 때
        mid = (left + right) // 2
        mergeSort(left, mid, list) #왼쪽 부분을 정렬
        mergeSort(mid + 1, right, list) #오른쪽 부분을 정렬
        
        merge(left, mid, right, list) #정렬된 두 배열을 합병

mergeSort(0, N - 1, list)

for n in list: print(n)