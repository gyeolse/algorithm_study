N = int(input())
array = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

max_val = -1e9
min_val = 1e9


def dfs(i, data):
    global add, sub, mul, div, max_val, min_val
    if i == N:
        max_val = max(max_val, data)
        min_val = min(min_val, data)
    else:
        if add > 0:
            add -= 1
            dfs(i + 1, data + array[i])
            add += 1
        if sub > 0:
            sub -= 1
            dfs(i + 1, data - array[i])
            sub += 1
        if mul > 0:
            mul -= 1
            dfs(i + 1, data * array[i])
            mul += 1
        if div > 0:
            div -= 1
            dfs(i + 1, int(data / array[i]))
            div += 1


dfs(1, array[0])
print(max_val)
print(min_val)