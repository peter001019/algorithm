import sys

n = sys.stdin.readline().strip()
caseList = []

while(n != '0'):
    caseList.append(n)
    n = sys.stdin.readline().strip()

for n in caseList:
    flag = True

    for i in range(len(n) // 2):
        if(n[i] != n[len(n) - i - 1]):
            flag = False
            break
    
    print("yes" if flag else "no")
    
    
