N = int(input())

num = 666
num1 = 0 # 앞부터 숫자를 채우는 경우
num2 = 6660 # 뒤에 숫자를 채우는 경우
zero = 1000 # 자리수

while(N > 0):
    num += 1000

    if(num > num2): # 6666 > 6660 인 경우 
        num1 = num
        num = num2
    
    if(num % zero == 9): #6669가 된 경우
        num2 = num + zero * 10 
        num = num1

    N -= 1