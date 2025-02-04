test_num = int(input())
results = []

def check(numbers, num):
    for n in numbers:
        if num < n:
            return False
    return True

for _ in range(test_num):
    N, M = map(int, input().split())
    count = 0
    num = 0

    numbers = list(map(int, input().split()))

    while(True):
        num = numbers.pop(0)

        if check(numbers, num): # 출력할 수 있는지 확인
            count += 1

            if M == 0: # M을 출력했다면 break
                break
        else:
            numbers.append(num)

        if(M == 0): # M이 출력되지 않고 뒤로 넘어가는 경우
            M = len(numbers) - 1
        else: # 한칸씩 출력할 경우, M을 한칸씩 앞으로
            M -= 1

    results.append(count)

for result in results:
    print(result)