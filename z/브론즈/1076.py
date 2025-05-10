dict = {"black": 0, "brown": 1, "red": 2, "orange": 3, "yellow": 4, "green": 5, "blue": 6, "violet": 7, "grey": 8, "white": 9}

list = []

for i in range(3):
    value = input()
    list.append(dict[value])

result = 0
result += list[0] * 10
result += list[1]
n = list[2]
result *= 10 ** n

print(result)