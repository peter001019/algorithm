import sys

parent = [0] * 53

for i in range(len(parent)): #먼저 자신의 집합으로 분류
    parent[i] = i

def find_parent(x):
    if(parent[x] != x):
        parent[x] = find_parent(parent[x])
        return parent[x]
    return x

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if(x != y):
        if(x < y):
            parent[y] = x
        else:
            parent[x] = y

N, M = map(int, (sys.stdin.readline()).split())
secondInput = (sys.stdin.readline()).split()
trueNum = int(secondInput.pop(0)) # 진실을 아는 사람 수
party = []
partyrow = []
result = M #진실을 말할 수 있는 파티 수

for n in secondInput: #진실을 아는 사람 0집합으로 분류
    parent[int(n)] = 0

for _ in range(M):
    thirdInput = (sys.stdin.readline()).split()
    peopleNum = int(thirdInput.pop(0)) # 파티의 사람 수
    partyrow.append(int(thirdInput[0]))

    for i in range(1, len(thirdInput)):
        partyrow.append(int(thirdInput[i]))
        union(int(thirdInput[i]), int(thirdInput[0])) #파티들의 그룹 합치기
    party.append(partyrow)
    partyrow = []

for row in party:
    for n in row:
        if(find_parent(n) == 0):
            result -= 1
            break

print(result)