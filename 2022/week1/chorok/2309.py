list = [int(input()) for _ in range(9)]
sum = sum(list)
nan1, nan2 = 0, 0

for i in range(9):
    for j in range(i + 1, 9):
        if sum - (list[i] + list[j]) == 100:
            nan1 = list[i]
            nan2 = list[j]
            break

list.remove(nan1)
list.remove(nan2)
list.sort()

for i in list:
    print(i)