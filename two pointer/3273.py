n = int(input())
a = list(map(int, input().split()))
x = int(input())

ans = 0

a.sort()

end = len(a) - 1

for i in range(len(a)):
    while end > i:
        if a[i] + a[end] == x:
            ans += 1
            end -= 1
            break

        else:
            if a[i] + a[end] > x:
                end -= 1
            else:
                break

print(ans)