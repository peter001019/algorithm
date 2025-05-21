L, C = map(int, input().split())
letters = list(input().split())
letters.sort()

ans = []
vowel = 'aeiou'


def backtracking(start, pwd):
    if len(pwd) == L:
        v_cnt = 0
        c_cnt = 0

        for p in pwd:
            if p in vowel:
                v_cnt += 1 
            else:
                c_cnt += 1
        
        if v_cnt >= 1 and c_cnt >= 2:
            ans.append(pwd)
        return

    for i in range(start, len(letters)):
        backtracking(i + 1, pwd + letters[i])

backtracking(0, '')

for a in ans:
    print(a)