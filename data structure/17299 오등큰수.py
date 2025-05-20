N = int(input())
A = list(map(int, input().split()))

#횟수를 저장
F = [0] * 1000001

#횟수 세기
for a in A:
    F[a] += 1

#stack은 오등큰수를 저장
stack = [A[-1]]
ans = [-1]

for i in range(len(A) - 2, -1, -1):
    while stack and F[stack[-1]] <= F[A[i]]:
        stack.pop()

    ans.append(stack[-1] if stack else -1)
    stack.append(A[i])

print(*ans[::-1])