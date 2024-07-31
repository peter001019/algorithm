N = int(input())

five = N // 5
while five >= 0:
    mod = (N - five * 5) % 3

    if mod == 0:
        three = (N - five * 5) // 3
        break
    five -= 1

if five < 0:
    print(-1)
else:
    print(five + three)


