import math

N = int(input())

mul = math.factorial(N)
result = 0
div = 10

while(True):
    if(mul % div == 0):
        div *= 10
        result += 1
    
    else:
        break

print(result)