N, S = map(int, input().split())
array = list(map(int, input().split()))
left, right, temp = 0, 0, 0
result = N + 1

while True:
    if temp >= S:
        result = min(result, right - left)
        temp -= array[left]
        left += 1
    elif right == N:
        break
    else:
        temp += array[right]
        right += 1

if result == N + 1:
    print(0)
else:
    print(result)