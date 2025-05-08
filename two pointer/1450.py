N, C = map(int, input().split())
w = list(map(int, input().split()))

start, end = 0, 0
sum = w[0]
ans = 1

while True:
    if start >= len(w):
        break

    if sum >= C:
        if sum == C:
            ans += 1

        sum -= w[start]
        start += 1

    else:
        ans += 1

        if end < len(w) - 1:
            end += 1
            sum += w[end]

print(ans)