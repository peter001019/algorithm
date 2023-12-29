X = int(input())

line = 1 #대각선 줄 개수
a = 1 #분자
b = 1 #분모
last = 1 #줄의 마지막 index 

while(last < X): #line 찾기
    line += 1
    last += line

diff = last - X #last와 찾고자하는 index의 거리
if(line % 2 == 0): #짝수번째 줄인 경우
    a = line - diff
    b = diff + 1
else: #홀수번째 줄인 경우
    a = diff + 1
    b = line - diff

print(f'{a}/{b}')
