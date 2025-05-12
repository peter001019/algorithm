from itertools import permutations

T = int(input())
words = [input() for _ in range(T)]

ans = []

for w in words:
    perm = permutations(w, len(w))
    list = []

    for p in perm:
        list.append(''.join(p))

    list.sort()
    
    for i in range(len(list)):
        if w == list[i]:
            if i == len(list) - 1:
                ans.append(list[i])
            else:
                ans.append(list[i + 1])
                break

for a in ans:
    print(a)