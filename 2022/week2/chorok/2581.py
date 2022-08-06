M = int(input())
N = int(input())
num = []

for i in range(M, N + 1):
    for j in range(2, i + 1):
        if j == i:
            num.append(i)
        if i % j == 0:
            break

if len(num) == 0:
    print(-1)
else:
    print(sum(num))
    print(min(num))