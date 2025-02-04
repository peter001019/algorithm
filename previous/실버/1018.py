import sys

N, M = map(int, input().split())

chess1 = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]
chess2 = [['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
          ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
          ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]
arr = [["" for _ in range(M)] for _ in range(N)]

for i in range(N): #체스판 입력
    string = input()
    arr[i] = list(string)

def check(chess, i, j):
    n = 0 #case의 False 개수

    for k in range(8):
        for l in range(8):     
            if(chess[k][l] != arr[i + k][j + l]):
                n += 1
    return n

falseNum = min(check(chess1, 0, 0), check(chess2, 0, 0))

#8*8 체스판과 비교
for i in range(N - 7):
    for j in range(M - 7):
        n = min(check(chess1, i, j), check(chess2, i, j))

        if(falseNum > n):
            falseNum = n        

print(falseNum)