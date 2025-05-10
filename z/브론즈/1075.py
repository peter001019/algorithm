N = (int(input()) // 100) * 100 
#백의 자리까지 없애는 방법, 100으로 나눈 몫을 구하고, 다시 100을 곱한다.
#int 형변환에 의해 소수점이 사라짐
F = int(input())

while(True):
    if(N % F != 0):
        N += 1

    else:
        break

result = N % 100
if(result < 10): print("0" + str(result))
else: print(result)

