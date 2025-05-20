N = int(input())
nums = list(map(int, input().split()))
stack = [nums[-1]]
ans = [-1]

for i in range(len(nums) - 2, -1, -1):
    #stack의 top 원소가 현재 num보다 커질 때 까지 pop 반복
    while stack and stack[-1] <= nums[i]:
        stack.pop()
    
    #stack에 요소가 남아있다면,오큰수 아니면 -1 push 
    ans.append(stack[-1] if stack else -1)
    
    #현재 요소 stack에 push
    stack.append(nums[i])

print(*ans[::-1])