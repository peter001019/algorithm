from itertools import permutations

T = int(input())
words = [input() for _ in range(T)]

ans = []

for w in words:
    w = list(w)

    #1. 바뀌는 블록 선택
    for i in range(len(w) - 2, -1, -1): 
        if w[i] < w[i + 1]:
            break
    
    if i == 0:
        ans.append(''.join(w))
        break

    m = 0

    #2. 그 다음 문자 찾고 교환
    for j in range(len(w) - 1, i, -1):
        if w[i] < w[j]:
            m = j
            break

    w[i], w[m] = w[m], w[i]

    #3. 뒤를 정렬
    w = w[:i + 1] + w[i + 1:][::-1]

    ans.append(''.join(w))

for a in ans:
    print(a)