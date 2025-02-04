import math  
import sys
sys.setrecursionlimit(10000)

N, r, c = map(int, input().split())
ans = (2 ** N) * (2 ** N) - 1

def recursive_Arr(N, r, c):
    global ans
    R = 2 ** N - 1
    C = R

    if(r == R and c == C):
        return ans

    #1사분면
    if(r <= R // 2 and c <= C // 2):
        ans -= (2 ** (N - 1)) * (2 ** (N - 1)) * 3
        return recursive_Arr(N - 1, r, c)

    #2사분면
    elif(r <= R // 2 and c <= C):
        ans -= (2 ** (N - 1)) * (2 ** (N - 1)) * 2
        return recursive_Arr(N - 1, r, c - 2 ** (N - 1))
    
    #3사분면
    elif(r <= R and c <= C // 2):
        ans -= (2 ** (N - 1)) * (2 ** (N - 1)) 
        return recursive_Arr(N - 1, r - 2 ** (N - 1), c)

    #4사분면
    else:
        return recursive_Arr(N - 1, r - 2 ** (N - 1), c - 2 ** (N - 1))
    
print(recursive_Arr(N, r, c))