T = int(input())
words = [input() for _ in range(T)]

ans = []

for w in words:
    w = list(w)
    found = False

    #1. 바뀌는 블록 선택
    for i in range(len(w) - 2, -1, -1): 
        if w[i] < w[i + 1]:
            found = True
            break

    if not found:
        ans.append(''.join(w))
        continue

    #2. 그 다음 문자 찾고 교환
    for j in range(len(w) - 1, i, -1):
        if w[i] < w[j]:
            break

    w[i], w[j] = w[j], w[i]

    #3. 뒤를 정렬
    w = w[:i + 1] + list(reversed(w[i + 1:]))
    ans.append(''.join(w))

for a in ans:
    print(a)